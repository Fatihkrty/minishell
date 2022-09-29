#include "../minishell.h"

void red_input(t_process *process)
{
	int fd;

	fd = open(process->execute[0], O_RDONLY);
	if (fd == -1)
		printf("No such file ! %d\n", fd);
	// else
	// 	ms.in_fd = fd;
}
