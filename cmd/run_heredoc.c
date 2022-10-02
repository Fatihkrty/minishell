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




void	run_heredoc(t_process *process, int in)
{
	pid_t	pid;
	int		fd[2];
	char	*path;
	char	*result;

	if (pipe(fd) < 0)
		return perror("PIPE ERROR");
	result = new_readline(get_endline(process->redirects));
	path = get_path(process->execute[0]);
	if (!path)
		return perror("ERROR");
	dup2(fd[0], 0);
	write(fd[1], result, ft_strlen(result));
	run_redirects(process, true);
	pid = fork();
	if (pid == 0)
	{
		if (ms.process_count > 1 && process->next != NULL)
			dup2(process->fd[1], 1);
		close_heredoc_fd(fd);
		execve(path, process->execute, NULL);
		exit(0);
	}
	close_heredoc_fd(fd);
	wait(NULL);
	dup2(in, 0);
	free(result);
	free(path);
}
