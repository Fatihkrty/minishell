/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkaratay <fkaratay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 20:15:43 by fkaratay          #+#    #+#             */
/*   Updated: 2022/01/13 12:00:25 by fkaratay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		neg;
	long	res;

	neg = 1;
	res = 0;
	while (*str == ' ' || *str == '\t' || \
			*str == '\n' || *str == '\r' || \
			*str == '\f' || *str == '\v')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			neg *= -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		res = res * 10 + (*str - '0');
		if (res * neg < INT_MIN)
			return (0);
		else if (res * neg > INT_MAX)
			return (-1);
		str++;
	}
	return (res * neg);
}
