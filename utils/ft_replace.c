#include "../minishell.h"

char	*ft_replace(char *str, char from, char from2, char to)
{
	int		i;
	char	*new_str;

	i = 0;
	new_str = malloc(sizeof(char) * ft_strlen(str) + 1);
	while (str[i])
	{
		if (str[i] == from || str[i] == from2)
			new_str[i] = to;
		else
			new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
