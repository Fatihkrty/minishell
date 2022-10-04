#include "../minishell.h"

void	red_input(char *file)
{
	int fd;

	file = clean_quote(file);
	fd = open(clean_quote(file), O_RDONLY);
	if (fd == -1)
		return perror("ERROR");
	if (is_parent())
		dup2(fd, ms.heredoc_fd[0]);
	else
		dup2(fd, 0);
	close(fd);
	free(file);
}
