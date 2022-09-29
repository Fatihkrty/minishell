#include "../minishell.h"

void	env_func()
{
	char	**env;

	env = ms.env;
	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
}