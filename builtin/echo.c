#include "../minishell.h"

void	builtin_echo(char	**input)
{
	int i;
	int	j;
	int flag;

	i = 1;
	flag = false;
	if (input[i] != NULL)
	{
		flag = ft_strcmp(input[i], "-n");
		if (flag)
			i++;
		while (input[i])
		{
			j = 0;
			while(input[i][j])
			{
				write(STDOUT_FILENO, &(input[i][j]), 1);
				j++;
			}
			if (input[i + 1])
				write(STDOUT_FILENO, " ", 1);
			i++;
		}
	}
	if (!flag)
		write(STDOUT_FILENO, "\n", 1);
	if (!is_parent())
        exit(EXIT_SUCCESS);
}