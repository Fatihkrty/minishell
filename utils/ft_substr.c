/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkaratay <fkaratay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 12:21:34 by fkaratay          #+#    #+#             */
/*   Updated: 2022/01/13 13:39:55 by fkaratay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*dest;
	size_t	srclen;

	if (str == 0)
		return ((char *)str);
	srclen = ft_strlen(str);
	if (srclen <= len)
		len = srclen;
	if (start >= srclen)
	{
		dest = malloc(1);
		*dest = 0;
		return (dest);
	}
	else
	{
		str += start;
		dest = (char *)malloc(sizeof(char) * (len + 1));
	}
	if (!dest)
		return (NULL);
	dest = ft_memcpy(dest, str, len);
	dest[len] = '\0';
	return (dest);
}
