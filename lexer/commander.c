#include "../minishell.h"

t_commander *init_commander()
{
	t_commander *commander;

	commander = ft_calloc(sizeof(t_commander), 1);
	commander->arguments = NULL;
	commander->prev = NULL;
	commander->next = NULL;
	return (commander);
}

void	commander_addback(t_commander **commander, t_commander *new_commander)
{
	t_commander *i_commander;

	i_commander = *commander;
	if (!(i_commander))
		*commander = new_commander;
	else
	{
		while (i_commander->next)
			i_commander = i_commander->next;
		i_commander->next = new_commander;
		new_commander->prev = i_commander;
	}
}