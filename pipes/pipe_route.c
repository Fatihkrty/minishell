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

void    pipe_route(t_process *process)
{
    if (process->prev == NULL)
        dup2(process->fd[1], 1);
    else if (process->next == NULL)
        dup2(process->prev->fd[0], 0);
    else
    {
        dup2(process->prev->fd[0], 0);
        dup2(process->fd[1], 1);
    }
    close_all_fd();
}