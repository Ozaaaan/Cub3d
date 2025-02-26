/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozdemir <ozdemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:22:58 by ozdemir           #+#    #+#             */
/*   Updated: 2025/02/26 16:31:15 by ozdemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	map_is_cub(char *filename)
{
	const char	*extension = ".cub";
	const char	*point = ft_strrchr(filename, '.');

	if (point != NULL && ft_strcmp(point, extension) == 0)
		return (1);
	return (0);
}

void    exit_error(char *str)
{
        printf("Error\n%s\n", str);
        exit(EXIT_FAILURE);
}

void    check_args(int ac, char **av)
{
        if (ac != 2)
                exit_error("Wrong number of arguments");
        if (map_is_cub(av[1]) != 1)
                exit_error("Map is not .cub");

}

void    free_tab(char **tab)
{
        int     i;

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

void    free_all(t_all *all)
{
        if (all->mlx)
                mlx_terminate(all->mlx);
        free(all);
}