/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozdemir <ozdemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:00:00 by ozdemir           #+#    #+#             */
/*   Updated: 2025/03/19 13:49:05 by ozdemir          ###   ########.fr       */
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

void	find_wall(t_all *all, t_ray *ray)
{
	while (ray->wall_hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->wall_hit_dir = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->wall_hit_dir = 1;
		}
		if (all->map_data[ray->map_y][ray->map_x] == '1')
			ray->wall_hit = 1;
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

uint32_t	get_texture_pixel(mlx_texture_t *texture, int x, int y)
{
	uint8_t	*r;
	uint8_t	*g;
	uint8_t	*b;
	uint8_t	*a;
	uint32_t color;

	int	index = (y * texture->width + x) * 4;
	r = &texture->pixels[index + 0];
	g = &texture->pixels[index + 1];
	b = &texture->pixels[index + 2];
	a = &texture->pixels[index + 3];
	color = (*a << 24) | (*b << 16) | (*g << 8) | (*r);
	return (color);
}


void	draw_wall(t_all *all, int x, t_ray *ray)
{
	int			y;
	int			tex_x;
	int			tex_y;
	double		step;
	double		tex_pos;
	uint32_t	color;
	mlx_texture_t *texture;

	if (ray->wall_hit_dir == 0)
		texture = (ray->ray_dir_x < 0) ? all->we_tex : all->ea_tex;
	else
		texture = (ray->ray_dir_y < 0) ? all->no_tex : all->so_tex;
	double wall_x;
	if (ray->wall_hit_dir == 0)
		wall_x = all->pos_y + ray->wall_dist * ray->ray_dir_y;
	else
		wall_x = all->pos_x + ray->wall_dist * ray->ray_dir_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (double)texture->width);
	if (ray->wall_hit_dir == 0 && ray->ray_dir_x > 0)
		tex_x = texture->width - tex_x - 1;
	if (ray->wall_hit_dir == 1 && ray->ray_dir_y < 0)
		tex_x = texture->width - tex_x - 1;
	step = 1.0 * texture->height / ray->wall_size;
	tex_pos = (ray->draw_start - HEIGHT / 2 + ray->wall_size / 2) * step;

	y = ray->draw_start;
	while (y <= ray->draw_end)
	{
		tex_y = (int)tex_pos & (texture->height - 1);
		tex_pos += step;
		color = get_texture_pixel(texture, tex_x, tex_y);
		mlx_put_pixel(all->img, x, y, color);
		y++;
	}
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
