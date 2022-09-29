#include "../minishell.h"

void	start_process()
{
	int			pos;
	t_process	*process;

	pos = 0;
	process = ms.process;
	ms.pids = ft_calloc(sizeof(int), ms.process_count);
	while (process)
	{
		run_cmd(process, pos);
		process = process->next;
		pos++;
	}
	pos = 0;
	while (pos < ms.process_count)
	{
		close_all_fd();
		waitpid(ms.pids[pos], NULL, 0);
		pos++;
	}
	free(ms.pids);
}
