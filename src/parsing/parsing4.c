/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-berr <cle-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:43:59 by ozdemir           #+#    #+#             */
/*   Updated: 2025/03/19 13:24:58 by cle-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_valid_texture_path(char *path)
{
	int	fd;

	if (!path || path[0] == '\0')
		return (0);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (1);
	close(fd);
	return (0);
}

void	store_texture_no(t_all *all, char *line)
{
	char	*trimmed_path;

	if (all->no)
	{
		free(line);
		exit_error_free_all(all, "Duplicate NO texture");
	}
	trimmed_path = ft_strtrim(line + 3, " \t\n\r");
	if (!trimmed_path || is_valid_texture_path(trimmed_path))
	{
		free(trimmed_path);
		if (all->ea)
			free(all->ea);
		if (all->so)
			free(all->so);
		if (all->we)
			free(all->we);
		close(all->fd);
		exit_error_free(line, "Invalid NO texture path");
	}
	all->no = trimmed_path;
}

void	store_texture_so(t_all *all, char *line)
{
	char	*trimmed_path;

	if (all->so)
	{
		free(line);
		exit_error_free_all(all, "Duplicate SO texture");
	}
	trimmed_path = ft_strtrim(line + 3, " \t\n\r");
	if (!trimmed_path || is_valid_texture_path(trimmed_path))
	{
		free(trimmed_path);
		if (all->ea)
			free(all->ea);
		if (all->we)
			free(all->we);
		if (all->no)
			free(all->no);
		close(all->fd);
		exit_error_free(line, "Invalid SO texture path");
	}
	all->so = trimmed_path;
}

void	store_texture_we(t_all *all, char *line)
{
	char	*trimmed_path;

	if (all->we)
	{
		free(line);
		exit_error_free_all(all, "Duplicate WE texture");
	}
	trimmed_path = ft_strtrim(line + 3, " \t\n\r");
	if (!trimmed_path || is_valid_texture_path(trimmed_path))
	{
		free(trimmed_path);
		if (all->ea)
			free(all->ea);
		if (all->so)
			free(all->so);
		if (all->no)
			free(all->no);
		close(all->fd);
		exit_error_free(line, "Invalid WE texture path");
	}
	all->we = trimmed_path;
}

void	store_texture_ea(t_all *all, char *line)
{
	char	*trimmed_path;

	if (all->ea)
	{
		free(line);
		exit_error_free_all(all, "Duplicate EA texture");
	}
	trimmed_path = ft_strtrim(line + 3, " \t\n\r");
	if (!trimmed_path || is_valid_texture_path(trimmed_path))
	{
		free(trimmed_path);
		if (all->we)
			free(all->we);
		if (all->so)
			free(all->so);
		if (all->no)
			free(all->no);
		close(all->fd);
		exit_error_free(line, "Invalid EA texture path");
	}
	all->ea = trimmed_path;
}
