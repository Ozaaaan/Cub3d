/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozdemir <ozdemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:15:04 by abesneux          #+#    #+#             */
/*   Updated: 2024/11/18 14:47:36 by ozdemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdlib.h>
#include <stdio.h>

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		i;

	if (!src)
		return (NULL);
	dest = malloc(ft_strlen(src) + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*
int	main(void)
{
	char src[] = "Salut !";
	printf("%s", ft_strdup(src));
	return (0);
}*/
