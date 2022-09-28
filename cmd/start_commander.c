#include "../minishell.h"

void	run_redirects(char **redirects)
{
	int	i;

	i = 0;
	while (redirects[i])
	{
		if (is_operator(redirects[i]) == RED_OUTPUT)
			red_output(redirects[i + 1], REPLACE);
		i++;
	}

}

int	create_process(t_commander *commander, t_fd_router *router)
{
	int			pid;

	pid = fork();
	if (pid == -1)
	{
		perror("ERROR");
		return -1;
	}
	if (pid == CHILD_PROCESS)
	{
		// run_redirects(commander->redirects);
		// run_cmd(commander->execute, router->fd);
	}
	return (pid);
}


void start_commander()
{
	t_commander	*commander;
	t_fd_router	*router;

	commander = ms.commander;
	create_pipes();
	router = ms.router;
	while (commander)
	{
		printf("While Process\n");
		run_cmd(commander, router);
		router = router->next;
		commander = commander->next;
	}
	printf("End While\n");
	wait(NULL);
	// wait(NULL);
	printf("End Program\n");
	// close_all_fd();
	// int len = ms.process_count;
	// while (len > 0)
	// {
	// 	wait(NULL);
	// }
	
	
}