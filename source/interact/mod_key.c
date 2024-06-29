/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 01:16:00 by ldulling          #+#    #+#             */
/*   Updated: 2024/06/29 17:23:16 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interact_private.h"

t_mod_key	*get_mod_key(void)
{
	static t_mod_key	mod_key;

	return (&mod_key);
}

bool	hold_mod_key(int key)
{
	if (toggle_mod_key(key))
		return (true);
	else if (key == XK_Shift_L || key == XK_Shift_R)
		*get_mod_key() |= K_SHIFT;
	else if (key == XK_Control_L || key == XK_Control_R)
		*get_mod_key() |= K_CTRL;
	else
		return (false);
	return (true);
}

bool	release_mod_key(int key)
{
	if (key == XK_Shift_L || key == XK_Shift_R)
		*get_mod_key() &= ~K_SHIFT;
	else if (key == XK_Control_L || key == XK_Control_R)
		*get_mod_key() &= ~K_CTRL;
	else
		return (false);
	return (true);
}

bool	toggle_mod_key(int key)
{
	if (key == XK_Alt_L || key == XK_Alt_R)
		*get_mod_key() ^= K_ALT;
	else
		return (false);
	return (true);
}
