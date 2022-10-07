#include "../minishell.h"

void	builtin_cd(char **input)
{
	char	*home;
    char    *err;
	
	if (input[1] != NULL)
    {
		if (chdir(input[1]) != 0)
            perror("minishell ");
    }
	else
	{
		home = getenv("HOME");
		if (home && *home)
			if (chdir(home))
				perror("minishell ");
	}
    if (!is_parent())
	    exit (errno);
}