/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 15:58:55 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/26 18:12:41 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader_private.h"

static bool		parse_line(t_scene *scene, char *line);
static t_scene	*parse_scene(int fd);

t_scene	*read_scene(char *filename)
{
	t_scene	*scene;
	int		fd;

	if (!is_valid_filename(filename))
	{
		print_error(INVALID_FILE_FMT);
		return (NULL);
	}
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		print_error(FAILED_OPEN_FILE);
		return (NULL);
	}
	scene = parse_scene(fd);
	if (close(fd) == -1)
	{
		print_error(FAILED_CLOSE_FILE);
		return (free_scene(&scene), NULL);
	}
	return (scene);
}

t_scene	*parse_scene(int fd)
{
	t_scene	*scene;
	char	*line;

	scene = (t_scene *)ft_calloc(1, sizeof(t_scene));
	if (!scene)
	{
		print_error(FAILED_ALLOC_MEM);
		return (NULL);
	}
	while (true)
	{
		line = get_next_line(fd);
		if (errno != 0)
		{
			print_error(FAILED_READ_FILE);
			return (free_get_next_line(), free_scene(&scene), NULL);
		}
		if (!line)
			break ;
		if (!parse_line(scene, line))
			return (free(line), free_get_next_line(), free_scene(&scene), NULL);
		free(line);
	}
	return (scene);
}

bool	parse_line(t_scene *scene, char *line)
{
	char	*id;

	id = ft_strtok(line, WHITESPACE);
	if (ft_strmatches_any(id, 3, "A", "C", "L"))
	{
		if (!parse_environment(scene, id))
			return (false);
	}
	else if (ft_strmatches_any(id, 3, "sp", "pl", "cy"))
	{
		if (!parse_object(scene, id))
			return (false);
	}
	else
	{
		print_error(INVALID_IDENTIFIER);
		return (false);
	}
	return (true);
}
