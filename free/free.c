#include "../minishell.h"

void	free_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_process()
{
	t_process	*process;
	t_process	*tmp;

	process = ms.process;
	free_array(process->execute);
	free_array(process->redirects);
	while (process)
	{
		tmp = process;
		process = process->next;
		free(tmp);
	}
}

void	free_app()
{
	free_process();
}