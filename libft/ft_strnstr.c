/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkaratay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 12:16:07 by fkaratay          #+#    #+#             */
/*   Updated: 2022/01/09 12:17:24 by fkaratay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char *find, size_t len)
{
	size_t	i;

	if (*find == '\0')
		return ((char *)src);
	i = ft_strlen((char *)find);
	while (*src && len >= i)
	{
		if (*src == *find && ft_memcmp(src, find, i) == 0)
			return ((char *)src);
		src++;
		len--;
	}
	return (NULL);
}
