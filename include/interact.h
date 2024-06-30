/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interact.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 01:02:26 by ldulling          #+#    #+#             */
/*   Updated: 2024/06/29 17:45:28 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERACT_H
# define INTERACT_H

# include "minirt.h"
# include "libft.h"

typedef enum e_interact_mode
{
	CAMERA,
	OBJECT,
	LIGHT,
	AMBLIGHT
}	t_interact_mode;

void			interact_camera(int key, t_minirt *minirt);
void			interact_object(int key, t_minirt *minirt);
void			interact_light(int key, t_minirt *minirt);
void			interact_amblight(int key, t_minirt *minirt);
t_interact_mode	*get_interact_mode(void);
bool			switch_interact_mode(int key);
bool			set_mod_key(int key);
bool			release_mod_key(int key);

#endif
