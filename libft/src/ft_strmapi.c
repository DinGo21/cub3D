/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <disantam@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 10:50:17 by disantam          #+#    #+#             */
/*   Updated: 2024/01/17 11:47:53 by disantam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		len;
	char	*str;

	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
	{
		return (NULL);
	}
	i = -1;
	while (s[++i] != '\0')
	{
		str[i] = f(i, s[i]);
	}
	str[i] = '\0';
	return (str);
}
