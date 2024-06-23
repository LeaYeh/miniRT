
#include "mlx_utils.h"

int	clean_and_exit(t_minirt *minirt)
{
	free_minirt(minirt);
	exit (0);
}

void	select_object(int key, t_minirt *minirt)
{
	if (key == XK_Tab)
	{
		if (minirt->mod_key & K_SHIFT)
			printf("Previous object\n");
		else
			printf("Next object\n");
	}
	else if (key == XK_1)
		printf("Select object 1\n");
	else if (key == XK_2)
		printf("Select object 2\n");
	else if (key == XK_3)
		printf("Select object 3\n");
	else if (key == XK_4)
		printf("Select object 4\n");
	else if (key == XK_5)
		printf("Select object 5\n");
	else if (key == XK_6)
		printf("Select object 6\n");
	else if (key == XK_7)
		printf("Select object 7\n");
	else if (key == XK_8)
		printf("Select object 8\n");
	else if (key == XK_9)
		printf("Select object 9\n");
}

void	translate_object(int key, t_minirt *minirt)
{
	(void)minirt;
	if (key == XK_w)
		printf("Move object forward\n");
	else if (key == XK_s)
		printf("Move object backward\n");
	else if (key == XK_a)
		printf("Move object left\n");
	else if (key == XK_d)
		printf("Move object right\n");
	else if (key == XK_x)
		printf("Move object up\n");
	else if (key == XK_z)
		printf("Move object down\n");
}

void	rotate_object(int key, t_minirt *minirt)
{
	if (key == XK_w)
		printf("Pitch object down\n");
	else if (key == XK_s)
		printf("Pitch object up\n");
	else if (key == XK_a)
		printf("Roll object left\n");
	else if (key == XK_d)
		printf("Roll object right\n");
	else if (key == XK_q)
		printf("Yaw object left\n");
	else if (key == XK_e)
		printf("Yaw object right\n");
	else
		translate_object(key, minirt);
}

void	transform_camera(int key, t_minirt *minirt)
{
	if (minirt->mod_key & K_SHIFT && key != XK_KP_Begin)
		printf("Fast ");
	if (key == XK_KP_Up)
		printf("Move camera forward\n");
	else if (key == XK_KP_Down)
		printf("Move camera backward\n");
	else if (key == XK_KP_Left)
		printf("Move camera left\n");
	else if (key == XK_KP_Right)
		printf("Move camera right\n");
	else if (key == XK_KP_Delete)
		printf("Move camera up\n");
	else if (key == XK_KP_Insert)
		printf("Move camera down\n");
	else if (key == XK_KP_Divide)
		printf("Pitch camera down\n");
	else if (key == XK_KP_Multiply)
		printf("Pitch camera up\n");
	else if (key == XK_KP_End)
		printf("Roll camera left\n");
	else if (key == XK_KP_Page_Down)
		printf("Roll camera right\n");
	else if (key == XK_KP_Home)
		printf("Yaw camera left\n");
	else if (key == XK_KP_Page_Up)
		printf("Yaw camera right\n");
	else if (key == XK_KP_Add)
		printf("Zoom in\n");
	else if (key == XK_KP_Subtract)
		printf("Zoom out\n");
	else if (key == XK_KP_Begin)
		printf("Reset camera\n");
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
		key == XK_KP_Begin)
		transform_camera(key, minirt);
	else if (key == XK_Tab || key == XK_1 || key == XK_2 || \
		key == XK_3 || key == XK_4 || key == XK_5 || \
		key == XK_6 || key == XK_7 || key == XK_8 || \
		key == XK_9)
		select_object(key, minirt);
	else if (key == XK_w || key == XK_a || key == XK_s || \
		key == XK_d || key == XK_z || key == XK_x || \
		key == XK_q || key == XK_e)
	{
		if (minirt->mod_key & K_SHIFT)
			printf("Fast ");
		if (minirt->mod_key & K_ALT || key == XK_q || key == XK_e)
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
