/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozdemir <ozdemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:20:20 by ozdemir           #+#    #+#             */
/*   Updated: 2025/02/26 16:10:24 by ozdemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "Libft/libft.h"
#include "MLX42.h"
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

#define WIDTH 1000
#define HEIGHT 800

typedef struct s_all
{
        void *mlx;
} t_all;

int	map_is_cub(char *filename);
void    exit_error(char *str);
void    free_tab(char **tab);
void    free_all(t_all *all);
void    check_args(int ac, char **av);

#endif