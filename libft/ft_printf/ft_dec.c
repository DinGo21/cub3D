/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <disantam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:35:54 by disantam          #+#    #+#             */
/*   Updated: 2024/06/05 13:15:31 by disantam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_litoa_len(long n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
	{
		len++;
	}
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*ft_litoa(long n)
{
	size_t	len;
	char	*str;

	len = ft_litoa_len(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
	{
		return (NULL);
	}
	str[len--] = '\0';
	if (n == 0)
	{
		str[0] = '0';
	}
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		str[len--] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

static int	ft_uitoa_len(size_t n)
{
	size_t	len;

	len = 0;
	if (n == 0)
	{
		len++;
	}
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*ft_uitoa(size_t n)
{
	size_t	len;
	char	*str;

	len = ft_uitoa_len(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
	{
		return (NULL);
	}
	str[len--] = '\0';
	if (n == 0)
	{
		str[0] = '0';
	}
	while (n > 0)
	{
		str[len--] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

int	ft_dec(long n, char f)
{
	int		c;
	char	*str;

	if (f == 'd' || f == 'i')
	{
		str = ft_litoa(n);
	}
	else
	{
		str = ft_uitoa(n);
	}
	c = -1;
	while (str[++c] != '\0')
	{
		write(1, str + c, 1);
	}
	free(str);
	return (c);
}
