/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <disantam@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:11:43 by disantam          #+#    #+#             */
/*   Updated: 2024/01/19 16:07:03 by disantam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		i = write(1, "(null)", 6);
	}
	else
	{
		while (s[i] != '\0')
		{
			i++;
		}
		write(1, s, i);
	}
	return (i);
}
