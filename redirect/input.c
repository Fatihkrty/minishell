#include "../minishell.h"

void	red_input(char *file)
{
	int fd;

	fd = open(clean_quote(file), O_RDONLY);
	if (is_parent())
	{
		if (fd == -1)
			return perror("minishell");
		dup2(fd, ms.heredoc_fd[0]);
	}
	else
	{
		if (fd == -1)
		{
			perror("minishell");
			exit(errno);
		}
		dup2(fd, 0);
	}
	close(fd);
}
