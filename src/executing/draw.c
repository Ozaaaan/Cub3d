/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-berr <cle-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 10:00:00 by ozdemir           #+#    #+#             */
/*   Updated: 2025/03/19 14:30:08 by cle-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	create_main_image(t_all *all)
{
	all->img = mlx_new_image(all->mlx, WIDTH, HEIGHT);
	if (!all->img)
		exit_error("Error creating image");
	if (mlx_image_to_window(all->mlx, all->img, 0, 0) < 0)
		exit_error("Error image to window");
}

void	draw_background(t_all *all)
{
	int	half_height;
	int	x;
	int	y;

	half_height = HEIGHT / 2;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (y < half_height)
				mlx_put_pixel(all->img, x, y, all->c);
			else
				mlx_put_pixel(all->img, x, y, all->f);
			x++;
		}
		y++;
	}
}

void	render(void *param)
{
	t_all	*all;

	all = (t_all *)param;
	draw_background(all);
	cast_rays(all);
	handle_movement(all);
}

void	draw_column(t_all *all, int x, t_ray *ray, int tex_x)
{
	int				y;
	int				tex_y;
	double			step;
	double			tex_pos;
	mlx_texture_t	*texture;

	texture = select_texture(all, ray);
	step = 1.0 * texture->height / ray->wall_size;
	tex_pos = (ray->draw_start - HEIGHT / 2 + ray->wall_size / 2) * step;
	y = ray->draw_start;
	while (y <= ray->draw_end)
	{
		tex_y = (int)tex_pos & (texture->height - 1);
		tex_pos += step;
		all->color = get_texture_pixel(texture, tex_x, tex_y, all);
		mlx_put_pixel(all->img, x, y, all->color);
		y++;
	}
}
