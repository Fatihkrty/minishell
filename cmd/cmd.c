#include "../minishell.h"

void	check_heredock(t_process *process)
{
	while (process)
	{
		if (is_heredoc(process))
			run_heredoc(process);
		process = process->next;
	}
}

void	check_cmd(t_process *process)
{
	while (process)
	{
		if (!is_heredoc(process))
			run_cmd(process);
		process = process->next;
	}
}

void	check_builtin(t_process *process, int type)
{
	int	in;
	int	out;

	in = dup(0);
	out = dup(1);
	run_redirects(process);
	run_builtin(process->execute, type);
	dup2(in, 0);
	dup2(out, 1);
	close(in);
	close(out);
}

void	wait_cmd(t_process *process)
{
	int a;
	while (process)
	{
		if (!is_heredoc(process))
		{
			close_all_fd();
			waitpid(process->pid, &a, 0);
			// printf("Child Status: %d\n", a % 255);
		}
		process = process->next;
	}
}

void	start_cmd()
{
	int			in;
	int			out;
	int			type;
	t_process	*process;

	process = ms.process;
	type = is_builtin(process->execute[0]);
	if (type && ms.process_count == 1 && !is_heredoc(process))
		check_builtin(process, type);
	check_heredock(process);
	check_cmd(process);
	wait_cmd(process);
}
