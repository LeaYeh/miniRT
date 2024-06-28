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
		dprintf(2, "Error: Invalid file format\n");
		return (NULL);
	}
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		dprintf(2, "Error: Failed to open file\n");
		return (NULL);
	}
	scene = parse_scene(fd);
	close(fd);
	return (scene);
}

t_scene	*parse_scene(int fd)
{
	t_scene	*scene;
	char	*line;

	scene = (t_scene *)ft_calloc(1, sizeof(t_scene));
	if (!scene)
	{
		dprintf(2, "Error: Failed to init scene.\n");
		return (NULL);
	}
	line = NULL;
	while (true)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (!parse_line(scene, line))
			return (free(line), free_scene(&scene), NULL);
		free(line);
	}
	return (scene);
}

bool	parse_line(t_scene *scene, char *line)
{
	char	**tokens;

	tokens = ft_split(line, ' ');
	if (!tokens)
		return (dprintf(2, "Error: Failed to split line\n"), false);
	else if (ft_strcmp(tokens[0], "A") == 0 || \
		ft_strcmp(tokens[0], "C") == 0 || \
		ft_strcmp(tokens[0], "L") == 0)
	{
		if (!parse_environment(scene, tokens))
			return (free_array(tokens), false);
	}
	else if (ft_strcmp(tokens[0], "sp") == 0 || \
		ft_strcmp(tokens[0], "pl") == 0 || \
		ft_strcmp(tokens[0], "cy") == 0)
	{
		if (!parse_object(scene, tokens))
			return (free_array(tokens), false);
	}
	else
		return (dprintf(2, "Error: Invalid identifier\n"),
			free_array(tokens), false);
	return (free_array(tokens), true);
}
