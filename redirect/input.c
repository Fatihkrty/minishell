#include "../minishell.h"

void	red_input(char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return perror("ERROR");
	dup2(fd, 0);
	close_heredoc_fd();
	close(fd);
}
