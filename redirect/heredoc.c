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

	result = "";
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
	write(0, result, ft_strlen(result));
	free(result);
}

void	run_heredoc(t_process *process)
{
	// printf("Data: %s\n", process->redirects[0]);
	pipe_route(process);
	red_heredoc(process->redirects[1]);
}