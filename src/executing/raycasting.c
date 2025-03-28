/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozdemir <ozdemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:00:00 by ozdemir           #+#    #+#             */
/*   Updated: 2025/03/19 14:12:57 by ozdemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_ray(t_all *all, int x, t_ray *ray)
{
	ray->plane_pos = 2 * x / (double)WIDTH - 1;
	ray->ray_dir_x = all->dir_x + all->plane_x * ray->plane_pos;
	ray->ray_dir_y = all->dir_y + all->plane_y * ray->plane_pos;
	ray->map_x = (int)all->pos_x;
	ray->map_y = (int)all->pos_y;
	ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
	ray->wall_hit = 0;
}

void	init_ray_direction(t_all *all, t_ray *ray)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (all->pos_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - all->pos_x) * ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (all->pos_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - all->pos_y) * ray->delta_dist_y;
	}
}

void	get_wall_size(t_all *all, t_ray *ray)
{
	if (ray->wall_hit_dir == 0)
		ray->wall_dist = (ray->map_x - all->pos_x + (1 - ray->step_x) / 2)
			/ ray->ray_dir_x;
	else
		ray->wall_dist = (ray->map_y - all->pos_y + (1 - ray->step_y) / 2)
			/ ray->ray_dir_y;
	ray->wall_size = (int)(HEIGHT / ray->wall_dist);
	ray->draw_start = -ray->wall_size / 2 + HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->wall_size / 2 + HEIGHT / 2;
	if (ray->draw_end >= HEIGHT)
		ray->draw_end = HEIGHT - 1;
}

void	cast_single_ray(t_all *all, int x)
{
	t_ray	ray;

	init_ray(all, x, &ray);
	init_ray_direction(all, &ray);
	find_wall(all, &ray);
	get_wall_size(all, &ray);
	draw_wall(all, x, &ray);
}

void	cast_rays(t_all *all)
{
	int	x;

	x = 0;
	while (x < WIDTH)
	{
		cast_single_ray(all, x);
		x++;
	}
}
