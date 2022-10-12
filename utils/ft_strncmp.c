#include "../minishell.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	while (n)
	{
		if (*str1 != *str2)
			return (*(unsigned char *)str1 - *(unsigned char *)str2);
		if (*str1 == 0)
			return (0);
		n--;
		str1++;
		str2++;
	}
	return (0);
}
