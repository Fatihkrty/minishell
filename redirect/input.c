#include "../minishell.h"

void	input(char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (is_parent())
	{
		if (fd == -1)
		{
			ms.ignore = true;
			return no_file_err(file);
		}
		dup2(fd, ms.heredoc_fd[0]);
	}
	else
	{
		if (fd == -1)
			no_file_err(file);
		dup2(fd, 0);
	}
	close(fd);
}
