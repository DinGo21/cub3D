/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <disantam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:50:54 by disantam          #+#    #+#             */
/*   Updated: 2024/06/05 11:16:00 by disantam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hex_conv(size_t n, char f)
{
	size_t	i;
	char	*base;

	i = 0;
	base = "0123456789abcdef";
	if (f == 'X')
	{
		base = "0123456789ABCDEF";
	}
	if (n >= 16)
	{
		i += ft_hex_conv(n / 16, f);
	}
	i += write(1, base + (n % 16), 1);
	return (i);
}

int	ft_hex(size_t n, char f)
{
	int	c;

	c = 2;
	if (f == 'p')
	{
		write(1, "0x", 2);
	}
	c += ft_hex_conv(n, f);
	return (c);
}
