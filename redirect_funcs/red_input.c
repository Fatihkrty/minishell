#include "../minishell.h"

void red_input(t_commander *commander)
{
	int fd;

	fd = open(commander->execute[0], O_RDONLY);
	if (fd == -1)
		printf("No such file ! %d\n", fd);
	else
		ms.in_fd = fd;
}
