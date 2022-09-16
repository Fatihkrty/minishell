#include "../minishell.h"

char	**init_arg_arr()
{
	char	**arg;

	arg = ft_calloc(sizeof(char **), 2);
	return (arg);
}


void	arg_arr_push(char ***arg_arr, char *str)
{
	int		len;
	int		i;
	char	**head;
	char	**new_arr;

	i = 0;
	len = 0;
	head = *arg_arr;
	while (head && head[len])
		len++;
	new_arr = ft_calloc(sizeof(char **), len + 2);
	while (i < len)
	{
		new_arr[i] = head[i];
		i++;
	}
	new_arr[i] = str;
	*arg_arr = new_arr;
}