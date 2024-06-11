/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <disantam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:43:50 by disantam          #+#    #+#             */
/*   Updated: 2024/05/29 16:00:30 by disantam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	ft_printf_check(int f, va_list args)
{
	int	c;

	c = 0;
	if (f == '%')
		c += write(1, "%", 1);
	if (f == 'd')
		c += ft_dec(va_arg(args, int), f);
	if (f == 'i')
		c += ft_dec(va_arg(args, int), f);
	if (f == 'c')
		c += ft_putchar(va_arg(args, int));
	if (f == 's')
		c += ft_putstr(va_arg(args, char *));
	if (f == 'p')
		c += ft_hex(va_arg(args, size_t), f);
	if (f == 'x')
		c += ft_hex(va_arg(args, unsigned int), f);
	if (f == 'u')
		c += ft_dec(va_arg(args, unsigned int), f);
	if (f == 'X')
		c += ft_hex(va_arg(args, unsigned int), f);
	return (c);
}

int	ft_printf(char const *s, ...)
{
	int		i;
	int		c;
	va_list	args;

	va_start(args, s);
	i = 0;
	c = 0;
	while (s[i] != '\0')
	{
		if (s[i] != '%')
		{
			c += write(1, s + i, 1);
		}
		else
		{
			c += ft_printf_check(s[++i], args);
		}
		i++;
	}
	va_end(args);
	return (c);
}
