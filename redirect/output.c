#include "../minishell.h"

void	red_output(char *file, int mode)
{
	int		fd;

	if (mode == REPLACE)
		fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0777);
	else if (mode == APPEND)
		fd = open(file, O_CREAT | O_WRONLY | O_APPEND, 0777);
	if (is_parent())
	{
		if (fd == -1)
			return perror("minishell");
	}
	else
	{
		if (fd == -1)
		{
			perror("minishell");
			exit(errno);
		}
	}
	dup2(fd, 1);
	close(fd);
}
