/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozdemir <ozdemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 12:20:55 by ozdemir           #+#    #+#             */
/*   Updated: 2025/03/04 14:13:26 by ozdemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_map(t_all **all, int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (line == NULL)
		exit_error("File is empty");
	while (line != NULL)
	{
		if (is_texture(line))
			store_texture(*all, line);
		else if (is_color(line))
			store_color(*all, line);
		else if (is_allowed_char(line))
			store_map(all, line);
		free(line);
		line = get_next_line(fd);
	}
	if ((*all)->count_no > 1 || (*all)->count_so > 1 || (*all)->count_we > 1
		|| (*all)->count_ea > 1 || (*all)->count_f > 1 || (*all)->count_c > 1)
		exit_error("More than 1 NO/SO/WE/EA/F/C");
}

void	init_map(t_all **all, char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		exit_error("Error opening file");
	parse_map(all, fd);
	close(fd);
}

void	parsing(t_all **all, int ac, char **av)
{
	check_args(ac, av);
	init_all(all);
	init_map(all, av[1]);
	wall_checker(*all);
}

void	check_args(int ac, char **av)
{
	if (ac != 2)
		exit_error("Wrong number of arguments");
	if (map_is_cub(av[1]) != 1)
		exit_error("Map is not .cub");
}

int	map_is_cub(char *filename)
{
	const char	*extension = ".cub";
	const char	*point = ft_strrchr(filename, '.');

	if (point != NULL && ft_strcmp(point, extension) == 0)
		return (1);
	return (0);
}
