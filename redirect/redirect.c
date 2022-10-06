#include "../minishell.h"

int	check_redirects(char **redirects)
{
	int	i;

	i = 0;
	while(redirects[i])
		i++;
	if (i % 2)
		return (false);
	return (true);
}

void	run_redirects(t_process *process)
{
	int		i;
	char	**redirects;

	i = 0;
	redirects = process->redirects;
	if (!check_redirects(redirects))
		token_err();
	while (redirects[i])
	{
		if (is_operator(redirects[i]) == RED_INPUT)
			red_input(redirects[i + 1]);
		else if (is_operator(redirects[i]) == RED_OUTPUT)
			red_output(redirects[i + 1], REPLACE);
		else if (is_operator(redirects[i]) == RED_APPEND)
			red_output(redirects[i + 1], APPEND);
		i+=2;
	}
}

void	get_all_inputs(t_process *process)
{
	int		i;
	char	**redirects;

	i = 0;
	redirects = process->redirects;
	if (!check_redirects(redirects))
		token_err();
	while (redirects[i])
	{
		if (is_operator(redirects[i]) == RED_INPUT)
			red_input(redirects[i + 1]);
		else if (is_operator(redirects[i]) == HERE_DOC)
			red_heredoc(redirects[i + 1]);
		i+=2;
	}
}

void	set_all_outputs(t_process *process)
{
	int		i;
	char	**redirects;

	i = 0;
	redirects = process->redirects;
	while (redirects[i])
	{
		if (is_operator(redirects[i]) == RED_OUTPUT)
			red_output(redirects[i + 1], REPLACE);
		else if (is_operator(redirects[i]) == RED_APPEND)
			red_output(redirects[i + 1], APPEND);
		i+=2;
	}
}
