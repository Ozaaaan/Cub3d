/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-berr <cle-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:09:06 by ozdemir           #+#    #+#             */
/*   Updated: 2025/03/19 15:14:01 by cle-berr         ###   ########.fr       */
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
}

void	init_textures(t_all *all)
{
	all->no_tex = mlx_load_png(all->no);
	all->so_tex = mlx_load_png(all->so);
	all->ea_tex = mlx_load_png(all->ea);
	all->we_tex = mlx_load_png(all->we);
	if (!all->no_tex || !all->so_tex || !all->ea_tex || !all->we_tex)
	{
		if (all->no_tex)
			mlx_delete_texture(all->no_tex);
		if (all->so_tex)
			mlx_delete_texture(all->so_tex);
		if (all->ea_tex)
			mlx_delete_texture(all->ea_tex);
		if (all->we_tex)
			mlx_delete_texture(all->we_tex);
		mlx_terminate(all->mlx);
		exit_error_free_all(all, "Invalid texture path");
	}
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

	parsing(&all, ac, av);
	print_map_data(&all);
	all.mlx = mlx_init(WIDTH, HEIGHT, "GAME", 1);
	init_player(&all);
	create_main_image(&all);
	init_textures(&all);
	mlx_loop_hook(all.mlx, render, &all);
	mlx_loop_hook(all.mlx, esc_key, &all);
	mlx_loop(all.mlx);
	mlx_delete_texture(all.no_tex);
	mlx_delete_texture(all.so_tex);
	mlx_delete_texture(all.ea_tex);
	mlx_delete_texture(all.we_tex);
	if (all.mlx)
		mlx_terminate(all.mlx);
	free_all(&all);
	return (0);
}
