#include "../minishell.h"

int get_args_len(char **args)
{
	char **head;

	head = args;
	while (*args)
		args++;
	return (args - head);
}

void red_output(t_commander *commander, int mode)
{
	int fd;
	int args_len;

	args_len = get_args_len(commander->arguments);
	if (args_len != 1)
	{
		printf("File args length error\n");
		return;
	}
	if (mode == REPLACE)
		fd = open(commander->arguments[0], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	else if (mode == APPEND)
		fd = open(commander->arguments[0], O_CREAT | O_WRONLY | O_APPEND, 0777);
	if (fd == -1)
		printf("Can not open file ! %d\n", fd);
	else
		ms.out_fd = fd;
}
