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

void start_commander()
{
	t_pipes	*pipes;
	t_commander	*commander;

	commander = ms.commander;
	create_pipes();
	pipes = ms.pipes;
	while (commander)
	{
		run_cmd(commander, pipes);
		pipes = pipes->next;
		commander = commander->next;
	}
	wait(NULL);
	wait(NULL);
}