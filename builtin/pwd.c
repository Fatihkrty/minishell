#include "../minishell.h"

void	builtin_pwd(char **input)
{
	char *result;

	result = getcwd((void *)0, 0);
	if (!result)
        perror("minishell ");
	else
		printf("%s\n", result);
    if (!is_parent())
        exit(errno);
}