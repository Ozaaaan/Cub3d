/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozdemir <ozdemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 10:00:00 by ozdemir           #+#    #+#             */
/*   Updated: 2025/03/19 14:09:25 by ozdemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	find_player_position(t_all *all)
{
	int	i;
	int	j;

	i = 0;
	while (all->map_data[i])
	{
		j = 0;
		while (all->map_data[i][j])
		{
			if (is_player(all->map_data[i][j]))
			{
				all->pos_x = j + 0.5;
				all->pos_y = i + 0.5;
				all->orientation = all->map_data[i][j];
				all->map_data[i][j] = '0';
				return ;
			}
			j++;
		}
		i++;
	}
}

void	set_player_ns_direction(t_all *all)
{
	if (all->orientation == 'N')
	{
		all->dir_x = 0;
		all->dir_y = -1;
		all->plane_x = 0.66;
		all->plane_y = 0;
	}
	if (all->orientation == 'S')
	{
		all->dir_x = 0;
		all->dir_y = 1;
		all->plane_x = -0.66;
		all->plane_y = 0;
	}
}

void	set_player_ew_direction(t_all *all)
{
	if (all->orientation == 'E')
	{
		all->dir_x = 1;
		all->dir_y = 0;
		all->plane_x = 0;
		all->plane_y = 0.66;
	}
	if (all->orientation == 'W')
	{
		all->dir_x = -1;
		all->dir_y = 0;
		all->plane_x = 0;
		all->plane_y = -0.66;
	}
}

void	init_player(t_all *all)
{
	find_player_position(all);
	set_player_ns_direction(all);
	set_player_ew_direction(all);
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
