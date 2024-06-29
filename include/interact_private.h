/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interact_private.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 15:34:09 by ldulling          #+#    #+#             */
/*   Updated: 2024/06/29 15:38:22 by ldulling         ###   ########.fr       */
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

t_mod_key	*get_mod_key(void);

bool		set_translation(t_vec3 *translation, int key);
bool		set_rotation(t_vec3 *rotation, int key);
bool		set_color(t_vec3 *color, int key);

bool		select_object(int key, t_list_d *objects);
t_obj		*get_selected_object(t_list_d *objects);
void		select_next_object(t_list_d *objects);
void		select_previous_object(t_list_d *objects);
void		select_n_object(int n, t_list_d *objects);

#endif
