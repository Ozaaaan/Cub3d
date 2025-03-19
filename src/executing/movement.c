/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-berr <cle-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:09:15 by ozdemir           #+#    #+#             */
/*   Updated: 2025/03/19 13:44:48 by cle-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_wall(t_all *all, double x, double y)
{
	if (x < 0 || y < 0)
		return (1);
	if ((int)y >= 0 && (int)x >= 0 && all->map_data[(int)y]
		&& all->map_data[(int)y][(int)x])
	{
		if (all->map_data[(int)y][(int)x] == '1')
			return (1);
	}
	return (0);
}

void	rotate_left(t_all *all, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = all->dir_x;
	all->dir_x = all->dir_x * cos(-rot_speed) - all->dir_y * sin(-rot_speed);
	all->dir_y = old_dir_x * sin(-rot_speed) + all->dir_y * cos(-rot_speed);
	old_plane_x = all->plane_x;
	all->plane_x = all->plane_x * cos(-rot_speed) - all->plane_y
		* sin(-rot_speed);
	all->plane_y = old_plane_x * sin(-rot_speed) + all->plane_y
		* cos(-rot_speed);
}

void	rotate_right(t_all *all, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = all->dir_x;
	all->dir_x = all->dir_x * cos(rot_speed) - all->dir_y * sin(rot_speed);
	all->dir_y = old_dir_x * sin(rot_speed) + all->dir_y * cos(rot_speed);
	old_plane_x = all->plane_x;
	all->plane_x = all->plane_x * cos(rot_speed) - all->plane_y
		* sin(rot_speed);
	all->plane_y = old_plane_x * sin(rot_speed) + all->plane_y * cos(rot_speed);
}

void	handle_movement(t_all *all)
{
	double	move_speed;
	double	rot_speed;

	move_speed = 0.05;
	rot_speed = 0.05;
	if (mlx_is_key_down(all->mlx, MLX_KEY_W))
		move_forward(all, move_speed);
	if (mlx_is_key_down(all->mlx, MLX_KEY_S))
		move_backward(all, move_speed);
	if (mlx_is_key_down(all->mlx, MLX_KEY_A))
		move_left(all, move_speed);
	if (mlx_is_key_down(all->mlx, MLX_KEY_D))
		move_right(all, move_speed);
	if (mlx_is_key_down(all->mlx, MLX_KEY_LEFT))
		rotate_left(all, rot_speed);
	if (mlx_is_key_down(all->mlx, MLX_KEY_RIGHT))
		rotate_right(all, rot_speed);
}
