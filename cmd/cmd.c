#include "../minishell.h"

void	start_cmd()
{
	int			in;
	int			out;
	t_process	*process;

	in = dup(0);
	out = dup(1);
	process = ms.process;
	while (process)
	{
		if (is_heredoc(process))
			run_heredoc(process);
		process = process->next;
	}
	dup2(in, 0);
	dup2(out, 1);
	close(in);
	close(out);
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
