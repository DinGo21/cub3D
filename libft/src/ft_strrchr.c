/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <disantam@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:52:37 by disantam          #+#    #+#             */
/*   Updated: 2024/01/17 12:08:33 by disantam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	if (s[i] == (char)c)
	{
		return ((char *)(s + i));
	}
	while (--i >= 0)
	{
		if (s[i] == (char)c)
		{
			return ((char *)(s + i));
		}
	}
	return (NULL);
}
