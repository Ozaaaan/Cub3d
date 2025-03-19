/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-berr <cle-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:02:44 by ozdemir           #+#    #+#             */
/*   Updated: 2025/03/19 14:29:08 by cle-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

uint32_t	get_texture_pixel(mlx_texture_t *texture, int x, int y, t_all *all)
{
	uint8_t		*r;
	uint8_t		*g;
	uint8_t		*b;
	uint8_t		*a;
	int			index;

	index = (y * texture->width + x) * 4;
	r = &texture->pixels[index + 0];
	g = &texture->pixels[index + 1];
	b = &texture->pixels[index + 2];
	a = &texture->pixels[index + 3];
	all->color = (*r << 24) | (*g << 16) | (*b << 8) | (*a);
	return (all->color);
}

mlx_texture_t	*select_texture(t_all *all, t_ray *ray)
{
	mlx_texture_t	*texture;

	if (ray->wall_hit_dir == 0)
	{
		if (ray->ray_dir_x < 0)
			texture = all->we_tex;
		else
			texture = all->ea_tex;
	}
	else
	{
		if (ray->ray_dir_y < 0)
			texture = all->no_tex;
		else
			texture = all->so_tex;
	}
	return (texture);
}

double	get_wall_x(t_all *all, t_ray *ray)
{
	double	wall_x;

	if (ray->wall_hit_dir == 0)
		wall_x = all->pos_y + ray->wall_dist * ray->ray_dir_y;
	else
		wall_x = all->pos_x + ray->wall_dist * ray->ray_dir_x;
	wall_x -= floor(wall_x);
	return (wall_x);
}

int	get_tex_x(t_ray *ray, mlx_texture_t *texture, double wall_x)
{
	int	tex_x;

	tex_x = (int)(wall_x * (double)texture->width);
	if (ray->wall_hit_dir == 0 && ray->ray_dir_x > 0)
		tex_x = texture->width - tex_x - 1;
	if (ray->wall_hit_dir == 1 && ray->ray_dir_y < 0)
		tex_x = texture->width - tex_x - 1;
	return (tex_x);
}

void	draw_wall(t_all *all, int x, t_ray *ray)
{
	double			wall_x;
	int				tex_x;
	mlx_texture_t	*texture;

	texture = select_texture(all, ray);
	wall_x = get_wall_x(all, ray);
	tex_x = get_tex_x(ray, texture, wall_x);
	draw_column(all, x, ray, tex_x);
}
