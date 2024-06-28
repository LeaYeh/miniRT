/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 21:00:37 by ldulling          #+#    #+#             */
/*   Updated: 2024/06/28 21:50:14 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_utils.h"
#include "transform.h"

int	clean_and_exit(t_minirt *minirt)
{
	mlx_destroy_window(minirt->mlx.mlx_ptr, minirt->mlx.win_ptr);
	mlx_destroy_image(minirt->mlx.mlx_ptr, minirt->mlx.img.img_ptr);
	mlx_destroy_display(minirt->mlx.mlx_ptr);
	free(minirt->mlx.mlx_ptr);
	free_minirt(minirt);
	exit (0);
}

t_list_d	**get_selected_object_node(t_minirt *minirt)
{
	static t_list_d	*selected_obj;

	if (!selected_obj)
		selected_obj = minirt->scene->objects;
	return (&selected_obj);
}

t_obj	*get_selected_object(t_minirt *minirt)
{
	return ((*get_selected_object_node(minirt))->content);
}

void	select_next_object(t_minirt *minirt)
{
	t_list_d	*next_obj;

	next_obj = (*get_selected_object_node(minirt))->next;
	if (!next_obj)
		next_obj = minirt->scene->objects;
	*get_selected_object_node(minirt) = next_obj;
}

void	select_previous_object(t_minirt *minirt)
{
	t_list_d	*prev_obj;

	prev_obj = (*get_selected_object_node(minirt))->prev;
	if (!prev_obj)
		prev_obj = ft_lstlast_d(minirt->scene->objects);
	*get_selected_object_node(minirt) = prev_obj;
}

void	select_n_object(int n, t_minirt *minirt)
{
	int	i;

	if (n > ft_lstsize_d(minirt->scene->objects))
		return ;
	i = 1;
	*get_selected_object_node(minirt) = minirt->scene->objects;
	while (i < n)
	{
		select_next_object(minirt);
		i++;
	}
}

void	select_object(int key, t_minirt *minirt)
{
	if (key == XK_Tab)
	{
		if (minirt->mod_key & K_SHIFT)
		{
			printf("Previous object\n");
			select_previous_object(minirt);
		}
		else
		{
			printf("Next object\n");
			select_next_object(minirt);
		}
	}
	else if (key == XK_1)
	{
		printf("Select object 1\n");
		select_n_object(1, minirt);
	}
	else if (key == XK_2)
	{
		printf("Select object 2\n");
		select_n_object(2, minirt);
	}
	else if (key == XK_3)
	{
		printf("Select object 3\n");
		select_n_object(3, minirt);
	}
	else if (key == XK_4)
	{
		printf("Select object 4\n");
		select_n_object(4, minirt);
	}
	else if (key == XK_5)
	{
		printf("Select object 5\n");
		select_n_object(5, minirt);
	}
	else if (key == XK_6)
	{
		printf("Select object 6\n");
		select_n_object(6, minirt);
	}
	else if (key == XK_7)
	{
		printf("Select object 7\n");
		select_n_object(7, minirt);
	}
	else if (key == XK_8)
	{
		printf("Select object 8\n");
		select_n_object(8, minirt);
	}
	else if (key == XK_9)
	{
		printf("Select object 9\n");
		select_n_object(9, minirt);
	}
}

void	translate_object(int key, t_minirt *minirt)
{
	double	translation;

	translation = INTERVAL_TRANSLATE;
	if (minirt->mod_key & K_SHIFT)
	{
		printf("Fast ");
		translation *= FACTOR_FAST;
	}
	if (key == XK_w)
	{
		printf("Move object forward\n");
		get_selected_object(minirt)->translation.z -= translation;
	}
	else if (key == XK_s)
	{
		printf("Move object backward\n");
		get_selected_object(minirt)->translation.z += translation;
	}
	else if (key == XK_a)
	{
		printf("Move object left\n");
		get_selected_object(minirt)->translation.x -= translation;
	}
	else if (key == XK_d)
	{
		printf("Move object right\n");
		get_selected_object(minirt)->translation.x += translation;
	}
	else if (key == XK_x)
	{
		printf("Move object up\n");
		get_selected_object(minirt)->translation.y += translation;
	}
	else if (key == XK_z)
	{
		printf("Move object down\n");
		get_selected_object(minirt)->translation.y -= translation;
	}
	else
		return ;
	minirt->stage |= OBJECT_CHANGE;
}

void	rotate_object(int key, t_minirt *minirt)
{
	double	rotation;

	rotation = INTERVAL_ROTATE;
	if (minirt->mod_key & K_SHIFT)
	{
		printf("Fast ");
		rotation *= FACTOR_FAST;
	}
	if (key == XK_w)
	{
		printf("Pitch object down\n");
		get_selected_object(minirt)->rotation.x -= rotation;
	}
	else if (key == XK_s)
	{
		printf("Pitch object up\n");
		get_selected_object(minirt)->rotation.x += rotation;
	}
	else if (key == XK_a)
	{
		printf("Roll object left\n");
		get_selected_object(minirt)->rotation.z -= rotation;
	}
	else if (key == XK_d)
	{
		printf("Roll object right\n");
		get_selected_object(minirt)->rotation.z += rotation;
	}
	else if (key == XK_q)
	{
		printf("Yaw object left\n");
		get_selected_object(minirt)->rotation.y -= rotation;
	}
	else if (key == XK_e)
	{
		printf("Yaw object right\n");
		get_selected_object(minirt)->rotation.y += rotation;
	}
	else
		return ;
	minirt->stage |= OBJECT_CHANGE;
}

void	reset_object(int key, t_minirt *minirt)
{
	t_obj	*obj;

	obj = get_selected_object(minirt);
	if (key == XK_space)
	{
		printf("Reset object orientation\n");
		obj->rotation = vector(0.0, 0.0, 0.0);
	}
	else if (key == XK_r)
	{
		printf("Reset object\n");
		obj->translation = vector(0.0, 0.0, 0.0);
		obj->rotation = vector(0.0, 0.0, 0.0);
	}
	else
		return ;
	minirt->stage |= OBJECT_CHANGE;
}


void	update_camera(int key, t_minirt *minirt)
{
	double	translation;
	double	rotation;

	translation = INTERVAL_TRANSLATE;
	rotation = INTERVAL_ROTATE;
	if (minirt->mod_key & K_SHIFT && key != XK_KP_Begin)
	{
		printf("Fast ");
		translation *= FACTOR_FAST;
		rotation *= FACTOR_FAST;
	}
	if (key == XK_KP_Up)
	{
		printf("Move camera forward\n");
		minirt->scene->camera.translation.z -= translation;
	}
	else if (key == XK_KP_Down)
	{
		printf("Move camera backward\n");
		minirt->scene->camera.translation.z += translation;
	}
	else if (key == XK_KP_Left)
	{
		printf("Move camera left\n");
		minirt->scene->camera.translation.x -= translation;
	}
	else if (key == XK_KP_Right)
	{
		printf("Move camera right\n");
		minirt->scene->camera.translation.x += translation;
	}
	else if (key == XK_KP_Delete)
	{
		printf("Move camera up\n");
		minirt->scene->camera.translation.y += translation;
	}
	else if (key == XK_KP_Insert)
	{
		printf("Move camera down\n");
		minirt->scene->camera.translation.y -= translation;
	}
	else if (key == XK_KP_Home)
	{
		printf("Yaw camera left\n");
		minirt->scene->camera.rotation.y -= rotation;
	}
	else if (key == XK_KP_Page_Up)
	{
		printf("Yaw camera right\n");
		minirt->scene->camera.rotation.y += rotation;
	}
	else if (key == XK_KP_End)
	{
		printf("Pitch camera down\n");
		minirt->scene->camera.rotation.x -= rotation;
	}
	else if (key == XK_KP_Page_Down)
	{
		printf("Pitch camera up\n");
		minirt->scene->camera.rotation.x += rotation;
	}
	else if (key == XK_KP_Divide)
	{
		printf("Roll camera left\n");
		minirt->scene->camera.rotation.z -= rotation;
	}
	else if (key == XK_KP_Multiply)
	{
		printf("Roll camera right\n");
		minirt->scene->camera.rotation.z += rotation;
	}
	else if (key == XK_KP_Add)
		printf("Zoom in\n");
	else if (key == XK_KP_Subtract)
		printf("Zoom out\n");
	else if (key == XK_KP_Begin)
	{
		printf("Reset camera orientation\n");
		minirt->scene->camera.rotation = vector(0.0, 0.0, 0.0);
	}
	else if (key == XK_KP_Enter)
	{
		printf("Reset camera\n");
		minirt->scene->camera.translation = vector(0.0, 0.0, 0.0);
		minirt->scene->camera.rotation = vector(0.0, 0.0, 0.0);
	}
	else
		return ;
	minirt->stage |= CAMERA_CHANGE;
}

int	handle_keypress_event(int key, t_minirt *minirt)
{
	if (key == XK_Escape)
		clean_and_exit(minirt);
	else if (key == XK_Shift_L || key == XK_Shift_R)
		minirt->mod_key |= K_SHIFT;
	else if (key == XK_Control_L || key == XK_Control_R)
		minirt->mod_key |= K_CTRL;
	else if (key == XK_Alt_L || key == XK_Alt_R)
		minirt->mod_key |= K_ALT;
	else if (key == XK_KP_Up || key == XK_KP_Down || \
		key == XK_KP_Left || key == XK_KP_Right || \
		key == XK_KP_Insert || key == XK_KP_Delete || \
		key == XK_KP_Home || key == XK_KP_Page_Up || \
		key == XK_KP_End || key == XK_KP_Page_Down || \
		key == XK_KP_Add || key == XK_KP_Subtract || \
		key == XK_KP_Divide || key == XK_KP_Multiply || \
		key == XK_KP_Begin || key == XK_KP_Enter)
		update_camera(key, minirt);
	else if (key == XK_Tab || key == XK_1 || key == XK_2 || \
		key == XK_3 || key == XK_4 || key == XK_5 || \
		key == XK_6 || key == XK_7 || key == XK_8 || \
		key == XK_9)
		select_object(key, minirt);
	else if (key == XK_w || key == XK_a || key == XK_s || \
		key == XK_d || key == XK_z || key == XK_x || \
		key == XK_q || key == XK_e || key == XK_space || key == XK_r)
	{
		if (key == XK_space || key == XK_r)
			reset_object(key, minirt);
		else if (minirt->mod_key & K_ALT || key == XK_q || key == XK_e)
			rotate_object(key, minirt);
		else
			translate_object(key, minirt);
	}
	else
		printf("key press: %x\n", key);
	return (0);
}

int	handle_keyrelease_event(int key, t_minirt *minirt)
{
	if (key == XK_Shift_L || key == XK_Shift_R)
		minirt->mod_key &= ~K_SHIFT;
	else if (key == XK_Control_L || key == XK_Control_R)
		minirt->mod_key &= ~K_CTRL;
	else if (key == XK_Alt_L || key == XK_Alt_R)
		minirt->mod_key &= ~K_ALT;
	return (0);
}

void	setup_event_hooks(t_minirt *minirt)
{
	mlx_hook(minirt->mlx.win_ptr,
		DestroyNotify, NoEventMask, clean_and_exit, minirt);
	mlx_hook(minirt->mlx.win_ptr,
		KeyPress, KeyPressMask, handle_keypress_event, minirt);
	mlx_hook(minirt->mlx.win_ptr,
		KeyRelease, KeyReleaseMask, handle_keyrelease_event, minirt);
}
