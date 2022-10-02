#include "../minishell.h"


void	run_heredoc(t_process *process)
{
	pid_t	pid;
	char	*path;

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
		execve(path, process->execute, NULL);
		exit(0);
	}
	close_heredoc_fd();
	wait(NULL);
	free(path);
}
