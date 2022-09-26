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

void	create_process(t_commander *commander)
{
	int			pid;

	pid = fork();
	if (pid == -1)
	{
		perror("ERROR");
		return;
	}
	run_redirects(commander->redirects);

}

void start_commander()
{
	t_commander	*commander;

	commander = ms.commander;
	while (commander)
	{
		create_process(commander);
		commander = commander->next;
	}
}