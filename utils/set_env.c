#include "../minishell.h"

void	set_env(char **env)
{
	size_t	i;
	size_t	len;
	char	**head;

	i = -1;
	head = env;
	while(*head)
		head++;
	len = head - env;
	ms.env = ft_calloc(sizeof(char **), len + 1);
	while (++i < len)
		ms.env[i] = env[i];
}