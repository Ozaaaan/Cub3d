/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-berr <cle-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:11:56 by ozdemir           #+#    #+#             */
/*   Updated: 2025/03/24 12:56:50 by cle-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	exit_error(char *str)
{
	printf("Error\n%s\n", str);
	exit(EXIT_FAILURE);
}

void	exit_error_free_all(t_all *all, char *str)
{
	if (str)
		printf("Error\n%s\n", str);
	free_all(all);
	exit(EXIT_FAILURE);
}

void	exit_error_free(char *line, char *str)
{
	free(line);
	printf("Error\n%s\n", str);
	exit(EXIT_FAILURE);
}

void	handle_empty_line(int *map_started, int *empty_line, char *line)
{
	if (*map_started)
		*empty_line = 1;
	free(line);
}
