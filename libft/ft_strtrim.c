/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkaratay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 12:18:58 by fkaratay          #+#    #+#             */
/*   Updated: 2022/01/09 12:20:47 by fkaratay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void	*ft_memcpy2(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest == src || n == 0)
		return (dest);
	i = 0;
	while (i < n)
	{
		*((char *)dest + i) = *((char *)src + i);
		i++;
	}
	return (dest);
}
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	char	*result;

	if (!s1)
		return (0);
	while (*s1 && ft_strchr(set, *s1) != 0)
		s1++;
	len = ft_strlen(s1);
	while (len && s1[len - 1] && ft_strchr(set, s1[len - 1]) != 0)
		len--;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (0);
	ft_memcpy2(result, s1, len);
	result[len] = '\0';
	return (result);
}
