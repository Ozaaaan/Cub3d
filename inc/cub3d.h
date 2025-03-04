/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozdemir <ozdemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:20:20 by ozdemir           #+#    #+#             */
/*   Updated: 2025/03/04 14:13:02 by ozdemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "Libft/libft.h"
# include "MLX42.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 1000
# define HEIGHT 800

typedef struct s_all
{
	char	**map;
	mlx_t	*mlx;
	char	*no;
	char	*so;
	char	*ea;
	char	*we;
	int		count_no;
	int		count_so;
	int		count_we;
	int		count_ea;
	int		count_f;
	int		count_c;
	int		f;
	int		c;
}			t_all;

int			map_is_cub(char *filename);
void		exit_error(char *str);
void		free_tab(char **tab);
void		free_all(t_all *all);
void		check_args(int ac, char **av);
void		parsing(t_all **all, int ac, char **av);
int			is_texture(char *line);
int			is_allowed_char(char *line);
int			is_color(char *line);
void		store_map(t_all **all, char *line);
void		store_color(t_all *all, char *line);
void		store_texture(t_all *all, char *line);
void		init_all(t_all **all);
void		wall_checker(t_all *all);
int			count_tab(char **tab);
int	ft_strlenn(char *str);
char    *skip_space(char *line);

#endif