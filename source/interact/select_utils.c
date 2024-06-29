/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 12:48:48 by ldulling          #+#    #+#             */
/*   Updated: 2024/06/29 16:21:59 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interact_private.h"

static t_list_d	**get_selected_node(t_list_d *list)
{
	static t_list_d	*selected_node;

	if (!selected_node)
		selected_node = list;
	return (&selected_node);
}

void	*get_selected_node_content(t_list_d *list)
{
	return ((*get_selected_node(list))->content);
}

void	select_next_node(t_list_d *list)
{
	t_list_d	*next_node;

	next_node = (*get_selected_node(list))->next;
	if (!next_node)
		next_node = list;
	*get_selected_node(list) = next_node;
}

void	select_previous_node(t_list_d *list)
{
	t_list_d	*prev_node;

	prev_node = (*get_selected_node(list))->prev;
	if (!prev_node)
		prev_node = ft_lstlast_d(list);
	*get_selected_node(list) = prev_node;
}

void	select_n_node(int n, t_list_d *list)
{
	int	i;

	if (n > ft_lstsize_d(list))
		return ;
	i = 1;
	*get_selected_node(list) = list;
	while (i < n)
	{
		select_next_node(list);
		i++;
	}
}
