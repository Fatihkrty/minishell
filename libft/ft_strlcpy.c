/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkaratay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 12:10:26 by fkaratay          #+#    #+#             */
/*   Updated: 2022/01/09 12:13:48 by fkaratay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	srclen;
	size_t	len;

	srclen = ft_strlen(src);
	if (size)
	{
		if (srclen >= size)
			len = size - 1;
		else
			len = srclen;
		ft_memcpy(dest, src, len);
		dest[len] = '\0';
	}
	return (srclen);
}
