/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-berr <cle-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:18:57 by ozdemir           #+#    #+#             */
/*   Updated: 2025/03/19 11:47:05 by cle-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	store_texture(t_all *all, char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		store_texture_no(all, line);
	else if (ft_strncmp(line, "SO ", 3) == 0)
		store_texture_so(all, line);
	else if (ft_strncmp(line, "WE ", 3) == 0)
		store_texture_we(all, line);
	else if (ft_strncmp(line, "EA ", 3) == 0)
		store_texture_ea(all, line);
}

void	storing(t_all *all, char *line)
{
	if (is_texture(line))
		store_texture(all, line);
	else if (is_color(line))
		store_color(all, line);
}

void	check_config(t_all *all)
{
	printf("no: %s\nso: %s\nea: %s\nwe: %s\nf: %d\nc: %d\n", all->no, all->so,
		all->ea, all->we, all->f, all->c);
	if (!all->no || !all->so || !all->ea || !all->we || !all->f || !all->c)
		exit_error("Missing textures or colors");
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
	int		i;
	int		j;

	i = 0;
	j = 0;
	while(str[i])
	{
		if (!str[i])
			return (0);
		j = -1;
		while(str[i][++j])
			if(!ft_isdigit(str[i][j]))
				return (0);
		i++;
	}
	return (1);
}
