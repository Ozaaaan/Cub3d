/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozdemir <ozdemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:20:20 by ozdemir           #+#    #+#             */
/*   Updated: 2025/03/24 17:39:54 by ozdemir          ###   ########.fr       */
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

typedef struct s_ray
{
	double			plane_pos;
	double			ray_dir_x;
	double			ray_dir_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			wall_dist;
	int				map_x;
	int				map_y;
	int				step_x;
	int				step_y;
	int				wall_hit;
	int				wall_hit_dir;
	int				wall_size;
	int				draw_start;
	int				draw_end;
}					t_ray;

typedef struct s_all
{
	char			**map_data;
	mlx_t			*mlx;
	char			*no;
	char			*so;
	char			*ea;
	char			*we;
	mlx_texture_t	*no_tex;
	mlx_texture_t	*so_tex;
	mlx_texture_t	*ea_tex;
	mlx_texture_t	*we_tex;
	int				fd;
	int				f;
	int				c;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	char			orientation;
	uint32_t		color;
	mlx_image_t		*img;
}					t_all;

int					map_is_cub(char *filename);
void				exit_error(char *str);
void				exit_error_free(char *line, char *str);
void				free_tab(char **tab);
void				free_all(t_all *all);
int					check_args(int ac, char **av);
void				parsing(t_all *all, int ac, char **av);
int					is_texture(char *line);
int					is_allowed_char(char *line);
int					is_color(char *line);
void				store_map(t_all *all, char *line);
void				store_color(t_all *all, char *line, char *freel);
void				store_texture(t_all *all, char *line, char *freel);
void				init_all(t_all *all);
int					wall_checker(t_all *all);
int					count_tab(char **tab);
int					ft_strlenn(char *str);
char				*skip_space(char *line);
void				storing(t_all *all, char *line, char *freel);
void				check_config(t_all *all);
void				count_player(t_all *all);
void				print_map_data(t_all *all);
int					is_player(char c);
int					char_allowed(char c);
int					check_valid_chars(t_all *all);
int					char_allowed(char c);
void				store_texture_ea(t_all *all, char *line, char *freel);
void				store_texture_we(t_all *all, char *line, char *freel);
void				store_texture_no(t_all *all, char *line, char *freel);
void				store_texture_so(t_all *all, char *line, char *freel);
int					is_valid_texture_path(char *path);
void				create_main_image(t_all *all);
void				render(void *param);
void				init_player(t_all *all);
void				tab_to_space(char *str);
void				exit_error_free_all(t_all *all, char *str);
int					strdigit(char **str);
void				handle_empty_line(int *map_started, int *empty_line,
						char *line);
void				comma_check(t_all *all, char *line, char *freel);

void				cast_rays(t_all *all);
void				init_ray(t_all *all, int x, t_ray *ray);
void				init_ray_direction(t_all *all, t_ray *ray);
void				find_wall(t_all *all, t_ray *ray);
void				get_wall_size(t_all *all, t_ray *ray);
void				draw_wall(t_all *all, int x, t_ray *ray);
void				cast_single_ray(t_all *all, int x);
void				handle_movement(t_all *all);
void				move_forward(t_all *all, double move_speed);
void				move_backward(t_all *all, double move_speed);
void				move_left(t_all *all, double move_speed);
void				move_right(t_all *all, double move_speed);
int					is_wall(t_all *all, double x, double y);
void				rotate_left(t_all *all, double rot_speed);
void				rotate_left(t_all *all, double rot_speed);
void				draw_column(t_all *all, int x, t_ray *ray, int tex_x);
mlx_texture_t		*select_texture(t_all *all, t_ray *ray);
uint32_t			get_texture_pixel(mlx_texture_t *texture, int x, int y,
						t_all *all);

#endif
