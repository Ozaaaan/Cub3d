/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozdemir <ozdemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 12:20:55 by ozdemir           #+#    #+#             */
/*   Updated: 2025/03/18 17:19:29 by ozdemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	handle_line(t_all *all, char *line, int *map_started)
{
	char	*copy;

	if (!line)
		return ;
	copy = skip_space(line);
	if (line[0] == '\0' || line[0] == '\n')
		free(line);
	else if (!(*map_started) && (is_texture(copy) || is_color(copy)))
	{
		storing(all, copy);
		free(line);
	}
	else if (is_allowed_char(line))
	{
		*map_started = 1;
		store_map(all, line);
	}
	else if (map_started)
		exit_error_free(line, "Invalid content");
	else
		free(line);
}

void	parse_map(t_all *all, int fd)
{
	char	*line;
	int		map_started;

	map_started = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		handle_line(all, line, &map_started);
	}
	if (!map_started)
		exit_error(all, "No correct map found");
}

void	parsing(t_all *all, int ac, char **av)
{
	int	fd;

	if (!check_args(ac, av))
		exit(EXIT_FAILURE);
	init_all(all);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Error\nError opening file\n");
		exit(EXIT_FAILURE);
	}
	parse_map(all, fd);
	close(fd);
	check_config(all);
	if (check_valid_chars(all))
		exit_error(all, "Invalid char in map");
	if (wall_checker(all))
		exit_error(all, "Map is not closed");
	count_player(all);
}

int	check_args(int ac, char **av)
{
	if (ac != 2)
		return(printf("Error\nWrong number of arguments\n"), 0);
	if (map_is_cub(av[1]))
		return(printf("Error\nMap is not .cub\n"), 0);
	return(1);
}

int	map_is_cub(char *filename)
{
	const char	*extension = ".cub";
	const char	*point = ft_strrchr(filename, '.');

	if (point != NULL && ft_strcmp(point, extension) == 0)
		return (0);
	return (1);
}
