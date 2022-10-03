#include "../minishell.h"


void	run_heredoc(t_process *process)
{
	pid_t	pid;
	char	*path;
	int		status;

	run_redirects(process, true);
	path = get_path(process->execute[0]);
	if (!path)
		return perror("ERROR");
	pid = fork();
	if (pid == 0)
	{
		dup2(ms.heredoc_fd[0], 0);
		if (ms.process_count > 1 && process->next != NULL)
			dup2(process->fd[1], 1);
		close_heredoc_fd();
		status = execve(path, process->execute, ms.env);
		free(path);
		exit(status);
	}
	close_heredoc_fd();
	wait(&ms.status);
	free(path);
}
