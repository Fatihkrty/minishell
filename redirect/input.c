#include "../minishell.h"

void	red_input(char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		printf("No such file ! %d\n", fd);
	dup2(fd, 0);
}
