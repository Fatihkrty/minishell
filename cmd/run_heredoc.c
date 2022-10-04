#include "../minishell.h"

void	close_heredoc_fd()
{
	close(ms.heredoc_fd[0]);
	close(ms.heredoc_fd[1]);
}

void	run_heredoc(t_process *process)
{
	pid_t	pid;
	char	*path;
	int		status;

	get_all_inputs(process);
	pid = fork();
	if (pid == 0)
	{
		path = get_path(process->execute[0]);
		dup2(ms.heredoc_fd[0], 0);
		if (ms.process_count > 1 && process->next != NULL)
			dup2(process->fd[1], 1);
		set_all_outputs(process);
		close_heredoc_fd();
		status = execve(path, process->execute, ms.env);
		free(path);
		exit(status);
	}
	wait(&ms.status);
}
