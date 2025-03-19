/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozdemir <ozdemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:11:56 by ozdemir           #+#    #+#             */
/*   Updated: 2025/03/19 11:42:28 by ozdemir          ###   ########.fr       */
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
