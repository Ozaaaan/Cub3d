/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozdemir <ozdemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:52:01 by ozdemir           #+#    #+#             */
/*   Updated: 2025/03/10 16:23:03 by ozdemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_invalid_space(char **map, int i, int j, int height)
{
	int	len;

	len = ft_strlenn(map[i]);
	return ((j > 0 && ft_isspace(map[i][j - 1])) || (j < len - 1
			&& ft_isspace(map[i][j + 1])) || (i > 0 && ft_isspace(map[i
				- 1][j])) || (i < height - 1 && ft_isspace(map[i + 1][j])));
}

int	char_allowed(char c)
{
	return (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' || c == 'W' || c == ' ');
}

int	check_valid_chars(t_all *all)
{
	int	i;
	int	j;

	i = -1;
	while (all->map_data[++i])
	{
		j = -1;
		while (all->map_data[i][++j])
		{
			if (!char_allowed(all->map_data[i][j]))
				return (1);
		}
	}
	return (0);
}

int is_surrounded_by_walls(char **map, int i, int j)
{
    int height;
    int len;

    height = 0;
    while (map[height])
        height++;
    len = ft_strlen(map[i]);
    if (i == 0 || j == 0 || i == height - 1 || j == len - 1)
        return (0);
    if (j == 0 && map[i][j] == ' ')
        return (0);
    if (i > 0 && j < ft_strlenn(map[i - 1]) && !char_allowed(map[i - 1][j]))
        return (0);
    if (i < height - 1 && j < ft_strlenn(map[i + 1]) && !char_allowed(map[i + 1][j]))
        return (0);
    if (j > 0 && !char_allowed(map[i][j - 1]))
        return (0);
    if (j < len - 1 && !char_allowed(map[i][j + 1]))
        return (0);
    return (1);
}

void	replace_inner_spaces(t_all *all)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	while (all->map_data[i])
	{
		j = 0;
		len = ft_strlenn(all->map_data[i]);
		while (all->map_data[i][j])
		{
			if (all->map_data[i][j] == ' '  && is_surrounded_by_walls(all->map_data, i, j))
				all->map_data[i][j] = '0';
			j++;
		}
		i++;
	}
}
