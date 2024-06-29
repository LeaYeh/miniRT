/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_object_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 12:48:48 by ldulling          #+#    #+#             */
/*   Updated: 2024/06/29 15:37:43 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interact_private.h"

static t_list_d	**get_selected_object_node(t_list_d *objects)
{
	static t_list_d	*selected_obj;

	if (!selected_obj)
		selected_obj = objects;
	return (&selected_obj);
}

t_obj	*get_selected_object(t_list_d *objects)
{
	return ((*get_selected_object_node(objects))->content);
}

void	select_next_object(t_list_d *objects)
{
	t_list_d	*next_obj;

	next_obj = (*get_selected_object_node(objects))->next;
	if (!next_obj)
		next_obj = objects;
	*get_selected_object_node(objects) = next_obj;
}

void	select_previous_object(t_list_d *objects)
{
	t_list_d	*prev_obj;

	prev_obj = (*get_selected_object_node(objects))->prev;
	if (!prev_obj)
		prev_obj = ft_lstlast_d(objects);
	*get_selected_object_node(objects) = prev_obj;
}

void	select_n_object(int n, t_list_d *objects)
{
	int	i;

	if (n > ft_lstsize_d(objects))
		return ;
	i = 1;
	*get_selected_object_node(objects) = objects;
	while (i < n)
	{
		select_next_object(objects);
		i++;
	}
}
