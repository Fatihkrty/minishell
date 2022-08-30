/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkaratay <fkaratay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 11:47:26 by fkaratay          #+#    #+#             */
/*   Updated: 2022/01/12 17:53:42 by fkaratay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *dest, const void *str, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*((unsigned char *)str + i) == (*((unsigned char *)dest + i)))
			i++;
		else
			return (*((unsigned char *)dest + i) - \
					(*((unsigned char *)str + i)));
	}
	return (0);
}
