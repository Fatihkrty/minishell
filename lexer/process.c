#include "../minishell.h"

t_process *init_process()
{
	t_process *process;

	process = ft_calloc(sizeof(t_process), 1);
	pipe(process->fd);
	process->execute = NULL;
	process->prev = NULL;
	process->next = NULL;
	return (process);
}

void	process_addback(t_process **process, t_process *new_process)
{
	t_process *i_process;

	i_process = *process;
	if (!(i_process))
		*process = new_process;
	else
	{
		while (i_process->next)
			i_process = i_process->next;
		i_process->next = new_process;
		new_process->prev = i_process;
	}
}