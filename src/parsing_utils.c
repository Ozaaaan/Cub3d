/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozdemir <ozdemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:14:49 by ozdemir           #+#    #+#             */
/*   Updated: 2025/03/03 15:10:38 by ozdemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	store_texture(t_all *all, char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
	{
		all->no = ft_strdup(line + 3);
		all->count_no += 1;
	}
	else if (ft_strncmp(line, "SO ", 3) == 0)
	{
		all->so = ft_strdup(line + 3);
		all->count_so += 1;
	}
	else if (ft_strncmp(line, "WE ", 3) == 0)
	{
		all->we = ft_strdup(line + 3);
		all->count_we += 1;
	}
	else if (ft_strncmp(line, "EA ", 3) == 0)
	{
		all->ea = ft_strdup(line + 3);
		all->count_ea += 1;
	}
}

int	parse_color(char *line)
{
	char	**colors;
	int		r;
	int		g;
	int		b;

	colors = ft_split(line, ',');
	if (!colors || !colors[0] || !colors[1] || !colors[2])
		exit_error("Invalid color format");
	r = ft_atoi(colors[0]);
	g = ft_atoi(colors[1]);
	b = ft_atoi(colors[2]);
	free_tab(colors);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		exit_error("Color values must be between 0 and 255");
	return ((r << 16) | (g << 8) | b);
}

void	store_color(t_all *all, char *line)
{
	if (line[0] == 'F')
	{
		all->f = parse_color(line + 2);
		all->count_f += 1;
	}
	else if (line[0] == 'C')
	{
		all->c = parse_color(line + 2);
		all->count_c += 1;
	}
}

void	first_init_map(t_all **all, char *line)
{
	(*all)->map = ft_calloc(2, sizeof(char *));
	(*all)->map[0] = ft_strdup(line);
	(*all)->map[1] = NULL;
}

void	store_map(t_all **all, char *line)
{
	char	**new_map;
	int		i;

	if (!(*all)->map)
		first_init_map(all, line);
	else
	{
		i = 0;
		while ((*all)->map[i])
			i++;
		new_map = ft_calloc(i + 2, sizeof(char *));
		i = 0;
		while ((*all)->map[i])
		{
			new_map[i] = ft_strdup((*all)->map[i]);
			i++;
		}
		new_map[i] = ft_strdup(line);
		new_map[i + 1] = NULL;
		free_tab((*all)->map);
		(*all)->map = new_map;
	}
}
