#include "../minishell.h"

void red_output(char *file, int mode)
{
	int fd;

	if (mode == REPLACE)
		fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0777);
	else if (mode == APPEND)
		fd = open(file, O_CREAT | O_WRONLY | O_APPEND, 0777);
	if (fd == -1)
		printf("Can not open file ! %d\n", fd);
	else
		ms.out_fd = fd;
}
