/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozdemir <ozdemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:09:06 by ozdemir           #+#    #+#             */
/*   Updated: 2025/03/19 11:27:34 by ozdemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_all(t_all *all)
{
	all->map_data = NULL;
	all->f = 0;
	all->c = 0;
	all->no = NULL;
	all->so = NULL;
	all->ea = NULL;
	all->we = NULL;
	all->pos_x = 0;
	all->pos_y = 0;
	all->dir_x = 0;
	all->dir_y = 0;
	all->plane_x = 0;
	all->plane_y = 0;
	all->orientation = '\0';
}

void	esc_key(void *esc)
{
	t_all	*all;

	all = (t_all *)esc;
	if (mlx_is_key_down(all->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(all->mlx);
}

int	main(int ac, char **av)
{
	t_all	all;

	ft_memset(&all, 0, sizeof(t_all));
	parsing(&all, ac, av);
	print_map_data(&all);
	all.mlx = mlx_init(WIDTH, HEIGHT, "GAME", 1);
	init_player(&all);
	create_main_image(&all);
	mlx_loop_hook(all.mlx, render, &all);
	mlx_loop_hook(all.mlx, esc_key, &all);
	mlx_loop(all.mlx);
	free_all(&all);
	return (0);
}
