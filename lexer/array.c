#include "../minishell.h"

char	**init_array()
{
	char	**arg;

	arg = ft_calloc(sizeof(char *), 1);
	return (arg);
}


char	**push_array(char **arg_arr, char *str)
{
	int		i;
	int		len;
	char	**new_arr;

	i = 0;
	len = 0;
	while (arg_arr && arg_arr[len])
		len++;
	new_arr = ft_calloc(sizeof(char *), len + 2);
	while (i < len)
	{
		new_arr[i] = arg_arr[i];
		i++;
	}
	new_arr[i] = str;
	return (new_arr);
}