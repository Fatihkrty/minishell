#include "../minishell.h"

void	set_env(char **env)
{
	size_t	i;
	size_t	len;
	char	**head;

	head = env;
	while(*head)
		head++;
	len = head - env;
	ms.env = ft_calloc(sizeof(char **), len + 1);
	i = -1;
	while (++i < len)
		ms.env[i] = ft_strdup(env[i]);
}
