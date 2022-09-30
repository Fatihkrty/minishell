#include "../minishell.h"

int check_endline(char *input, char *endline)
{
	int len;

	len = ft_strlen(endline);
	if (ft_strlen(input) == len)
		if (!ft_strncmp(input, endline, len))
			return (true);
	return (false);
}

void red_heredoc(char *endline)
{
	char *tmp;
	char *input;
	char *result;

	tmp = ft_calloc(1,1);
	result = "";
	// int pid = fork();
	// if (pid == 0)
	// {
		while (1)
		{
			input = readline("heredoc >> ");
			if (check_endline(input, endline))
				break;
			input = ft_strjoin(input, "\n");
			tmp = result;
			result = ft_strjoin(result, input);
			free(input);
			if (*tmp)
				free(tmp);
		}
		write(1, result, ft_strlen(result));
		free(result);
		exit(0);
	// }
	// else
	// {
	// 	wait(NULL);
	// 	exit(0);
	// }
}