#include "../minishell.h"

void	red_input(char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("ERROR");
		return ;
	}
	dup2(fd, 0);
}
