#include "../minishell.h"

void    close_all_fd()
{
	t_process *process;

	process = ms.process;
	while (process)
	{
		close(process->fd[0]);
		close(process->fd[1]);
		process = process->next;
	}
}

void	close_heredoc_fd()
{
	close(ms.heredoc_fd[0]);
	close(ms.heredoc_fd[1]);
}