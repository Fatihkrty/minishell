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
	int a;
	while (pos < ms.process_count)
	{
		close_all_fd();
		waitpid(ms.pids[pos], &a, 0);
		// printf("HATA: %d %s\n", a, strerror(a));
		pos++;
	}
	free(ms.pids);
}
