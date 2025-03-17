/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-berr <cle-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:20:22 by ozdemir           #+#    #+#             */
/*   Updated: 2025/03/17 15:16:31 by cle-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_map_data(t_all *all)
{
	int	i;

	i = 0;
	printf("Contenu de map_data :\n");
	while (all->map_data[i])
	{
		printf("[%s]\n", all->map_data[i]);
		i++;
	}
}

int	is_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

int	 is_invalid_position(char **map, int i, int j)
{
	int	height;
	int	len;

	height = 0;
	while (map[height])
		height++;
	len = ft_strlenn(map[i]);
	if (i == 0 || i == height - 1 || j == 0 || j == len - 1)
		return (1);
	if ((j > 0 && map[i][j - 1] == ' ') || (j < len - 1 && map[i][j + 1] == ' ')
		|| map[i - 1][j] == ' ' || map[i + 1][j] == ' ' 
		|| map[i - 1][j + 1] == ' ' || map[i + 1][j - 1] == ' '
		|| map[i - 1][j - 1] == ' ' || map[i + 1][j + 1] == ' '
		|| !map[i - 1][j] || !map[i + 1][j] 
		|| !map[i - 1][j + 1] || !map[i + 1][j - 1]
		|| !map[i - 1][j - 1] || !map[i + 1][j + 1])
		return (1);
	return (0);
}

int	wall_checker(t_all *all)
{
	int	i;
	int	j;

	i = 0;
	while (all->map_data[i])
	{
		j = 0;
		while (all->map_data[i][j])
		{
			if (all->map_data[i][j] == '0' || is_player(all->map_data[i][j]))
			{
				if (is_invalid_position(all->map_data, i, j))
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	count_player(t_all *all)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (all->map_data[i])
	{
		j = 0;
		while (all->map_data[i][j])
		{
			if (all->map_data[i][j] == 'N' || all->map_data[i][j] == 'S'
				|| all->map_data[i][j] == 'E' || all->map_data[i][j] == 'W')
				count++;
			j++;
		}
		i++;
	}
	if (count != 1)
		exit_error("Map must contain exactly one player starting position");
}
