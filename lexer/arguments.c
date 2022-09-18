#include "../minishell.h"

char	**init_arg_arr()
{
	char	**arg;

	arg = ft_calloc(sizeof(char **), 2);
	return (arg);
}


char	**arg_arr_push(char **arg_arr, char *str)
{
	int		i;
	int		len;
	char	**new_arr;

	i = 0;
	len = 0;
	while (arg_arr && arg_arr[len])
		len++;
	new_arr = ft_calloc(sizeof(char **), len + 2);
	while (i < len)
	{
		new_arr[i] = arg_arr[i];
		i++;
	}
	new_arr[i] = str;
	return (new_arr);
}