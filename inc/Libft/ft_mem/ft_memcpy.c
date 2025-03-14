/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 09:58:23 by abesneux          #+#    #+#             */
/*   Updated: 2023/10/19 22:50:50 by abesneux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stddef.h>
#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*destination;
	const char	*source;

	destination = dest;
	source = src;
	i = 0;
	if (dest == 0 && src == 0)
		return (NULL);
	while (i < n)
	{
		destination[i] = source[i];
		i++;
	}
	return (dest);
}
/*
int	main(void)
{
	char source[] = "Salut";
	char destination[20];

	ft_memcpy(destination, source, sizeof(source));
	printf("Source : %s\n", source);
	printf("Destination : %s\n", destination);
	return (0);
}*/
