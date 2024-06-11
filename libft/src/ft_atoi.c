/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <disantam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 19:56:01 by disantam          #+#    #+#             */
/*   Updated: 2024/06/05 11:19:46 by disantam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		result;
	char	sign;

	result = 0;
	sign = 0;
	while ((*str == 32) || (*str >= 9 && *str <= 13))
		str++;
	while ((*str == '-' || *str == '+') && (*str < '0' || *str > '9'))
	{
		if (*str == '-' && sign != '-' && sign != '+')
			sign = '-';
		else if (*str == '+' && sign != '-' && sign != '+')
			sign = '+';
		else
			return (result);
		str++;
	}
	while (*str != '\0' && *str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str++ - '0');
	}
	if (sign == '-')
		return (-result);
	return (result);
}
