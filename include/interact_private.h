/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interact_private.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 15:34:09 by ldulling          #+#    #+#             */
/*   Updated: 2024/06/29 21:49:58 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERACT_PRIVATE_H
# define INTERACT_PRIVATE_H

# include "minirt.h"
# include "interact.h"

typedef enum e_modifier_key
{
	K_SHIFT	= 1 << 0,
	K_CTRL	= 1 << 1,
	K_ALT	= 1 << 2
}	t_mod_key;

typedef enum e_scale_mode
{
	DIAMETER,
	HEIGHT,
	BOTH,
	SCALE_MODE_COUNT
}	t_scale_mode;

t_mod_key	*get_mod_key(void);

bool		set_translation(t_vec3 *translation, int key);
bool		set_rotation(t_vec3 *rotation, int key);
bool		set_scale(t_obj *obj, int key);
bool		set_color(t_vec3 *color, int key);

bool		select_object(int key, t_list_d *list);
void		*get_selected_node_content(t_list_d *list);
void		select_next_node(t_list_d *list);
void		select_previous_node(t_list_d *list);
void		select_n_node(int n, t_list_d *list);

#endif
