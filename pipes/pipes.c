#include "../minishell.h"

t_pipes	*init_pipes()
{
	t_pipes	*pipes;

	pipes = ft_calloc(sizeof(t_pipes), 1);
	pipes->next = NULL;
	pipes->prev = NULL;
	return (pipes);
}

void	pipes_addback(t_pipes **pipes, t_pipes *new_pipes)
{
	t_pipes	*i_pipes;

	i_pipes = *pipes;
	if (!i_pipes)
		*pipes = new_pipes;
	else
	{
		while (i_pipes->next)
			i_pipes = i_pipes->next;
		i_pipes->next = new_pipes;
		new_pipes->prev = i_pipes;
	}
}

void	create_pipes()
{
	int		len;
	t_pipes	*pipes;

	len = ms.process_count;
	while (len > 0)
	{
		pipes_addback(&ms.pipes, init_pipes());
		len--;
	}
	pipes = ms.pipes;
	while (pipes->next)
	{
		pipe(pipes->fd);
		pipes = pipes->next;
	}
}
