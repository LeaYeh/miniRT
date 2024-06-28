/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:18:37 by lyeh              #+#    #+#             */
/*   Updated: 2024/06/25 19:45:16 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "reader.h"
# include "environment.h"
# include "camera.h"
# include "utils.h"
# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>

typedef enum e_stage
{
	NO_CHANGE,
	LIGHT_CHANGE,
	OBJECT_CHANGE,
	CAMERA_CHANGE
}	t_stage;

typedef enum e_modifier_key
{
	K_SHIFT	= 1 << 0,
	K_CTRL	= 1 << 1,
	K_ALT	= 1 << 2
}	t_mod_key;

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_img;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
}	t_mlx;

typedef struct s_minirt
{
	t_mlx		mlx;
	t_scene		*scene;
	t_ray		*ray_pool;
	t_stage		stage;
	t_mod_key	mod_key;
}	t_minirt;

bool	init_minirt(t_minirt *minirt, char *filename);
void	free_minirt(t_minirt *minirt);
void	reset_ray_pool(t_ray *ray_pool, t_camera *camera);

#endif
