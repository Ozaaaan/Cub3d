/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozdemir <ozdemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:20:22 by ozdemir           #+#    #+#             */
/*   Updated: 2025/03/03 15:37:36 by ozdemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	wall_checker(t_all *all)
{
	int	i;
	int	j;

	i = 0;
	while (all->map[i])
	{
		j = 0;
		while (all->map[i][j])
		{
			if (i == 0 || i == count_tab(all->map) - 1 || j == 0 || j == ft_strlenn(all->map[i]) - 1)
			{
				if (all->map[i][j] != '1')
					exit_error("Map must be surrounded by walls");
			}
			j++;
		}
		i++;
	}
}
