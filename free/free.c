#include "../minishell.h"

void	free_paths()
{
	int	i;

	i = 0;
	while (ms.paths[i])
	{
		free(ms.paths[i]);
		i++;
	}
	free(ms.paths);
}

void	free_arrays(char **arr)
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
	free_arrays(process->execute);
	free_arrays(process->redirects);
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