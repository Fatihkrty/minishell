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

void	close_heredoc_fd(int *fd)
{
	close(fd[0]);
	close(fd[1]);
}

void red_heredoc(char *endline, t_process *process)
{
	pid_t pid;
	int fd[2];
	char *tmp;
	char *input;
	char *result;

	pipe(fd);
	result = "";
	while (1)
	{
		input = readline("heredoc >> ");
		if (check_endline(input, endline) || !input)
			break;
		if (!input)
			input = "eof";
		input = ft_strjoin(input, "\n");
		tmp = result;
		result = ft_strjoin(result, input);
		free(input);
		if (*tmp)
			free(tmp);
	}
	dup2(fd[0], 0);
	write(fd[1], result, ft_strlen(result));
	close_heredoc_fd(fd);
	pid = fork();
	if (pid == 0)
	{
		if (ms.process_count > 1 && process->next != NULL)
			dup2(process->fd[1], 1);
		execve("/usr/bin/cat", process->execute, NULL);
	}
	close_heredoc_fd(fd);
	wait(NULL);
	free(result);
}

void	run_heredoc(t_process *process)
{
	// printf("Data: %s\n", process->redirects[0]);
	// pipe_route(process);

	red_heredoc(process->redirects[1], process);
}