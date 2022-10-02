#include "../minishell.h"

void	start_process()
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
	int a;
	process = ms.process;
	while (process)
	{
		close_all_fd();
		waitpid(process->pid, &a, 0);
		// printf("PROCESS: %d => %d %s\n", process->pid, a, strerror(a));
		process = process->next;
	}
}
