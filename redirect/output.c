#include "../minishell.h"

void	output(t_process *process, char *file, int mode)
{
	int		fd;

	if (mode == REPLACE)
		fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0777);
	else if (mode == APPEND)
		fd = open(file, O_CREAT | O_WRONLY | O_APPEND, 0777);
	if (fd == -1)
	{
		perror("minishell");
		if (is_parent())
			return;
		else
			exit(errno);
	}
	dup2(fd, 1);
	close(fd);
}
