#include "../minishell.h"

void	check_builtin(t_process *process)
{
	int	in;
	int	out;

	in = dup(0);
	out = dup(1);
	run_redirects(process);
	run_builtin(process->execute);
	dup2(in, 0);
	dup2(out, 1);
	close(in);
	close(out);
}

void	wait_cmd(t_process *process)
{
	while (process)
	{
		close_all_fd();
		close_heredoc_fd();
		waitpid(process->pid, &errno, 0);
		printf("Child Status: %d\n", errno % 255);
		process = process->next;
	}
}

void	start_cmd()
{
	t_process	*process;

	process = ms.process;
	if (is_builtin(process->execute[0]) && ms.process_count == 1 && !is_heredoc(process))
		check_builtin(process);
	else
	{
		run_cmd(process);
		wait_cmd(process);
	}
}
