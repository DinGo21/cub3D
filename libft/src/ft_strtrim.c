/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <disantam@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:59:38 by disantam          #+#    #+#             */
/*   Updated: 2023/10/25 16:29:32 by disantam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	j = 0;
	size = ft_strlen(s1) - 1;
	while (set[j] != '\0')
		if (s1[i] != set[j])
			j++;
		else
		{
			i++;
			j = 0;
		}
	j = 0;
	while (set[j] != '\0')
		if (s1[size] != set[j])
			j++;
		else
		{
			size--;
			j = 0;
		}
	return (ft_substr(s1, i, size - i + 1));
}
