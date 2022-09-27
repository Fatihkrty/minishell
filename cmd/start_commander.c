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
		run_cmd(commander->execute, router->fd);
	}
	return (pid);
}


void start_commander()
{
	int i;
	t_commander	*commander;
	t_fd_router	*router;

	i = 0;
	route_pipes();
	commander = ms.commander;
	router = ms.router;
	while (commander)
	{
		run_cmd(commander->execute, router->fd);
		router = router->next;
		commander = commander->next;
		i++;
	}
	close(ms.fd[0]);
	close(ms.fd[1]);
	// router = ms.router;
	// while (router)
	// {
	// 	close(router->fd[0]);
	// 	close(router->fd[1]);
	// 	router = router->next;
	// }
	router = ms.router;
	while (router)
	{
		wait(NULL);
		router = router->next;
	}
	
}