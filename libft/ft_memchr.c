/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkaratay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 11:46:12 by fkaratay          #+#    #+#             */
/*   Updated: 2022/01/09 11:46:57 by fkaratay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t	id;

	id = 0;
	while (id < n)
	{
		if (*((unsigned char *)str + id) == (unsigned char)c)
			return ((void *)str + id);
		id++;
	}
	return (0);
}
