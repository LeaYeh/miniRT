/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 01:02:48 by ldulling          #+#    #+#             */
/*   Updated: 2024/06/29 23:09:49 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTILS_H
# define MLX_UTILS_H

# include "minirt.h"
# include "interact.h"
# include "transform.h"

bool	init_mlx(t_mlx *mlx);
void	free_mlx(t_mlx *mlx);
void	img_pixel_put(t_img *img, int x, int y, int color);
void	setup_event_hooks(t_minirt *minirt);

#endif
