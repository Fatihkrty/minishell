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

void red_heredoc(t_commander *commander)
{
	char *tmp;
	char *input;
	char *result;
	char *endline;

	input = NULL;
	tmp = input;
	result = "";
	endline = commander->arguments[0];
	pipe(ms.fd);
	int pid = fork();
	if (pid == 0)
	{
		close(ms.fd[0]);
		while (1)
		{
			input = readline("heredoc>> ");
			if (check_endline(input, endline))
				break;
			input = ft_strjoin(input, "\n");
			tmp = result;
			result = ft_strjoin(result, input);
			free(input);
			if (*tmp)
				free(tmp);
		}
		write(ms.fd[1], result, ft_strlen(result));
		free(result);
		close(ms.fd[1]);
		exit(0);
	}
	else
	{
		close(ms.fd[1]);
		wait(NULL);
		dup2(ms.fd[0], 0);
		close(ms.fd[0]);
	}
}