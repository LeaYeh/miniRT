/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hit_record.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:13:21 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/17 13:36:35 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

void	print_hit_record(t_hit_record *rec)
{
	printf("Hit Record:\n");
	printf("Point: ");
	print_vector(rec->point);
	printf("Normal: ");
	print_vector(rec->norm);
	printf("Color: ");
	print_vector(rec->color);
	printf("Front Face: %d\n", rec->front_face);
	printf("T: %f\n", rec->t);
}

void	print_hit_record_list(t_list *rec_list)
{
	t_list			*curr;
	t_hit_record	*rec;

	curr = rec_list;
	while (curr)
	{
		rec = curr->content;
		print_hit_record(rec);
		curr = curr->next;
	}
}
