#include "../minishell.h"

void	builtin_env()
{
	char	**env;

	env = ms.env;
	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
}