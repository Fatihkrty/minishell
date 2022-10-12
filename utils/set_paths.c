#include "../minishell.h"

void	set_paths(void)
{
	char	*path;

	path = get_env("PATH");
	if (!(*path))
		ms.paths = NULL;
	else
	{
		if (ms.paths)
			free_array(ms.paths);
		ms.paths = ft_split(path, ':');
	}
	free(path);
}
