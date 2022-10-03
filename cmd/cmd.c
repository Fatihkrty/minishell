#include "../minishell.h"

void	start_cmd()
{
	t_process	*process;

	process = ms.process;
	while (process)
	{
		if (is_heredoc(process))
			run_heredoc(process);
		process = process->next;
	}
	process = ms.process;
	while (process)
	{
		if (!is_heredoc(process))
			run_cmd(process);
		process = process->next;
	}
	process = ms.process;
	while (process)
	{
		close_all_fd();
		waitpid(process->pid, &ms.status, 0);
		process = process->next;
	}
}
