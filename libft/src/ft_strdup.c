/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <disantam@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:22:56 by disantam          #+#    #+#             */
/*   Updated: 2024/01/17 12:05:35 by disantam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	c;
	char	*str;

	c = ft_strlen(s1) + 1;
	str = malloc(c);
	if (!str)
	{
		return (NULL);
	}
	i = 0;
	while (i < c)
	{
		str[i] = s1[i];
		i++;
	}
	return (str);
}
