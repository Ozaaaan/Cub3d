/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozdemir <ozdemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:09:06 by ozdemir           #+#    #+#             */
/*   Updated: 2025/03/17 12:16:32 by ozdemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_all(t_all **all)
{
	*all = ft_calloc(1, sizeof(t_all));
	(*all)->map = NULL;
	(*all)->map_data = NULL;
	(*all)->f = 0;
	(*all)->c = 0;
	(*all)->no = NULL;
	(*all)->so = NULL;
	(*all)->ea = NULL;
	(*all)->we = NULL;
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
	t_all	*all;

	parsing(&all, ac, av);
	/* 	all->mlx = mlx_init(WIDTH, HEIGHT, "GAME", 1);
		mlx_loop_hook(all->mlx, esc_key, all);
		mlx_loop(all->mlx); */
	free_all(all);
	return (0);
}
