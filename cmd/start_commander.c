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

int	create_process(t_commander *commander)
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
		run_redirects(commander->redirects);
		run_cmd(commander->execute);
	}
	return (pid);

}

int	get_process_len()
{
	int			len;
	t_commander *commander;

	len = 0;
	commander = ms.commander;
	while(commander)
	{
		len++;
		commander = commander->next;
	}
	return (len);
}

void start_commander()
{
	t_commander	*commander;

	commander = ms.commander;
	ms.process_id = malloc(sizeof(int) * get_process_len());
	int i = 0;
	while (commander)
	{
		ms.process_id[i] = create_process(commander);
		commander = commander->next;
		i++;
	}
	i = 0;
	while (i < get_process_len())
	{
		waitpid(ms.process_id[i], NULL, 0);
		i++;
	}
}