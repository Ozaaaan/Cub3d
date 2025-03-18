/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozdemir <ozdemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:52:01 by ozdemir           #+#    #+#             */
/*   Updated: 2025/03/18 12:44:59 by ozdemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	char_allowed(char c)
{
	return (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' || c == 'W'
		|| c == ' ' || c == '\t');
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
