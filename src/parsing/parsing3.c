/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-berr <cle-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:18:57 by ozdemir           #+#    #+#             */
/*   Updated: 2025/03/24 14:16:18 by cle-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	store_texture(t_all *all, char *line, char *freel)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		store_texture_no(all, line, freel);
	else if (ft_strncmp(line, "SO ", 3) == 0)
		store_texture_so(all, line, freel);
	else if (ft_strncmp(line, "WE ", 3) == 0)
		store_texture_we(all, line, freel);
	else if (ft_strncmp(line, "EA ", 3) == 0)
		store_texture_ea(all, line, freel);
}

void	storing(t_all *all, char *line, char *freel)
{
	if (is_texture(line))
		store_texture(all, line, freel);
	else if (is_color(line))
		store_color(all, line, freel);
}

void	check_config(t_all *all)
{
	if (!all->no || !all->so || !all->ea || !all->we || !all->f || !all->c)
	{
		exit_error_free_all(all, "Missing textures or colors");
	}
}

void	tab_to_space(char *str)
{
	if (!str)
		return ;
	while (*str)
	{
		if (*str == '\t')
			*str = ' ';
		str++;
	}
}

int	strdigit(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i][0] == '\n')
			return (0);
		j = 0;
		while (str[i][j] && str[i][j] != '\n')
		{
			if (!ft_isdigit(str[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
