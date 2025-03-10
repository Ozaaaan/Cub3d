/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozdemir <ozdemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:22:58 by ozdemir           #+#    #+#             */
/*   Updated: 2025/03/04 15:25:56 by ozdemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char    *skip_space(char *line)
{
        while (*line && (*line == ' ' || *line == '\t'))
                line++;
        return(line);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	ft_strlenn(char *str)
{
	int	i;

	while (str[i])
		i++;
	return (i);
}

int	count_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	free_all(t_all *all)
{
	if (all->mlx)
		mlx_terminate(all->mlx);
	if (all->map_data)
		free_tab(all->map_data);
	free(all);
}
