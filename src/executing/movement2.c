/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-berr <cle-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:25:51 by ozdemir           #+#    #+#             */
/*   Updated: 2025/03/19 13:44:45 by cle-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward(t_all *all, double move_speed)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = all->pos_x + all->dir_x * move_speed;
	new_pos_y = all->pos_y + all->dir_y * move_speed;
	if (!is_wall(all, new_pos_x, all->pos_y))
		all->pos_x = new_pos_x;
	if (!is_wall(all, all->pos_x, new_pos_y))
		all->pos_y = new_pos_y;
}

void	move_backward(t_all *all, double move_speed)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = all->pos_x - all->dir_x * move_speed;
	new_pos_y = all->pos_y - all->dir_y * move_speed;
	if (!is_wall(all, new_pos_x, all->pos_y))
		all->pos_x = new_pos_x;
	if (!is_wall(all, all->pos_x, new_pos_y))
		all->pos_y = new_pos_y;
}

void	move_left(t_all *all, double move_speed)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = all->pos_x - all->plane_x * move_speed;
	new_pos_y = all->pos_y - all->plane_y * move_speed;
	if (!is_wall(all, new_pos_x, all->pos_y))
		all->pos_x = new_pos_x;
	if (!is_wall(all, all->pos_x, new_pos_y))
		all->pos_y = new_pos_y;
}

void	move_right(t_all *all, double move_speed)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = all->pos_x + all->plane_x * move_speed;
	new_pos_y = all->pos_y + all->plane_y * move_speed;
	if (!is_wall(all, new_pos_x, all->pos_y))
		all->pos_x = new_pos_x;
	if (!is_wall(all, all->pos_x, new_pos_y))
		all->pos_y = new_pos_y;
}
