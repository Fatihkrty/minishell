#include "../minishell.h"

char	**set_env(char **env)
{
	size_t	i;
	size_t	len;
	char	**head;
	char	**result;

	i = -1;
	head = env;
	while(*head)
		head++;
	len = head - env;
	result = ft_calloc(sizeof(char **), len + 1);
	while (++i < len)
		result[i] = env[i];
	return (result);
}