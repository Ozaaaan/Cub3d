/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozdemir <ozdemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:18:57 by ozdemir           #+#    #+#             */
/*   Updated: 2025/03/17 14:58:49 by ozdemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	store_texture(t_all *all, char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		store_texture_no(all, line);
	else if (ft_strncmp(line, "SO ", 3) == 0)
		store_texture_so(all, line);
	else if (ft_strncmp(line, "WE ", 3) == 0)
		store_texture_we(all, line);
	else if (ft_strncmp(line, "EA ", 3) == 0)
		store_texture_ea(all, line);
}

void	storing(t_all **all, char *line)
{
	if (is_texture(line))
		store_texture(*all, line);
	else if (is_color(line))
		store_color(*all, line);
}

void	check_config(t_all *all)
{
	printf("no: %s\nso: %s\nea: %s\nwe: %s\nf: %d\nc: %d\n", all->no, all->so,
		all->ea, all->we, all->f, all->c);
	if (!all->no || !all->so || !all->ea || !all->we || !all->f || !all->c)
		exit_error("Missing textures or colors");
}
