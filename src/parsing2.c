/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozdemir <ozdemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:14:49 by ozdemir           #+#    #+#             */
/*   Updated: 2025/03/18 11:03:57 by ozdemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

uint32_t	parse_color(t_all *all, char *line)
{
	char		**colors;
	int			r;
	int			g;
	int			b;
	uint32_t	color;

	colors = ft_split(line, ',');
	if (!colors || !colors[0] || !colors[1] || !colors[2])
		exit_error(all, "Invalid color format");
	r = (uint8_t)ft_atoi(colors[0]);
	g = (uint8_t)ft_atoi(colors[1]);
	b = (uint8_t)ft_atoi(colors[2]);
	free_tab(colors);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		exit_error(all, "Color values must be between 0 and 255");
	color = (r << 24) | (g << 16) | (b << 8) | 0xFF;
	return (color);
}

void	store_color(t_all *all, char *line)
{
	if (line[0] == 'F')
	{
		if (all->f)
			exit_error(all, "Duplicate F");
		all->f = parse_color(all, line + 2);
	}
	else if (line[0] == 'C')
	{
		if (all->c)
			exit_error(all, "Duplicate C");
		all->c = parse_color(all, line + 2);
	}
}

void	first_init_map(t_all *all, char *line)
{
	all->map_data = ft_calloc(2, sizeof(char *));
	if (!all->map_data)
		exit_error(all, "Malloc failed");
	all->map_data[0] = ft_strdup(line);
	all->map_data[1] = NULL;
}

void	add_map_line(t_all *all, char *cleaned_line)
{
	char	**new_map;
	int		i;

	i = 0;
	while (all->map_data[i])
		i++;
	new_map = ft_calloc(i + 2, sizeof(char *));
	if (!new_map)
		exit_error(all, "Malloc failed");
	i = 0;
	while (all->map_data[i])
	{
		new_map[i] = ft_strdup(all->map_data[i]);
		i++;
	}
	new_map[i] = ft_strdup(cleaned_line);
	new_map[i + 1] = NULL;
	free_tab(all->map_data);
	all->map_data = new_map;
}

void	store_map(t_all *all, char *line)
{
	char	*cleaned_line;

	cleaned_line = ft_strtrim(line, "\n");
	tab_to_space(cleaned_line);
	free(line);
	if (!all->map_data)
		first_init_map(all, cleaned_line);
	else
		add_map_line(all, cleaned_line);
	free(cleaned_line);
}
