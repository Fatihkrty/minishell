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
	int a;
	while (process)
	{
		close_all_fd();
		waitpid(process->pid, &a, 0);
		strerror(a);
		// printf("Child Status: %d\n", a % 256);
		process = process->next;
	}
}
