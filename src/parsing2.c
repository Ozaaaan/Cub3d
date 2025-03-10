/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozdemir <ozdemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:14:49 by ozdemir           #+#    #+#             */
/*   Updated: 2025/03/06 16:13:46 by ozdemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	store_texture(t_all *all, char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
	{
		if (all->no)
			exit_error_free(line, "Duplicate NO");
		all->no = ft_strdup(line + 3);
	}
	else if (ft_strncmp(line, "SO ", 3) == 0)
	{
		if (all->so)
			exit_error_free(line, "Duplicate SO");
		all->so = ft_strdup(line + 3);
	}
	else if (ft_strncmp(line, "WE ", 3) == 0)
	{
		if (all->we)
			exit_error_free(line, "Duplicate WE");
		all->we = ft_strdup(line + 3);
	}
	else if (ft_strncmp(line, "EA ", 3) == 0)
	{
		if (all->ea)
			exit_error_free(line, "Duplicate EA");
		all->ea = ft_strdup(line + 3);
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
		if (all->f)
			exit_error_free(line, "Duplicate F");
		all->f = parse_color(line + 2);
	}
	else if (line[0] == 'C')
	{
		if (all->c)
			exit_error_free(line, "Duplicate C");
		all->c = parse_color(line + 2);
	}
}

void	first_init_map(t_all **all, char *line)
{
	(*all)->map_data = ft_calloc(2, sizeof(char *));
	if (!(*all)->map_data)
		exit_error("Malloc failed");
	(*all)->map_data[0] = ft_strdup(line);
	(*all)->map_data[1] = NULL;
}

void	store_map(t_all **all, char *line)
{
	char	*cleaned_line;
	char	**new_map;
	int		i;

	cleaned_line = ft_strtrim(line, "\n");
	if (!(*all)->map_data)
		first_init_map(all, cleaned_line);
	else
	{
		i = 0;
		while ((*all)->map_data[i])
			i++;
		new_map = ft_calloc(i + 2, sizeof(char *));
		i = 0;
		while ((*all)->map_data[i])
		{
			new_map[i] = ft_strdup((*all)->map_data[i]);
			i++;
		}
		new_map[i] = ft_strdup(cleaned_line);
		new_map[i + 1] = NULL;
		free_tab((*all)->map_data);
		(*all)->map_data = new_map;
	}
}
