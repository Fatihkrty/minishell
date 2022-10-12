#include "../minishell.h"

void	run_redirects(t_process *process)
{
	int		i;
	char	**redirects;

	i = 0;
	redirects = process->redirects;
	while (redirects[i])
	{
		if (is_operator(redirects[i]) == RED_INPUT)
			input(redirects[i + 1]);
		else if (is_operator(redirects[i]) == RED_OUTPUT)
			output(process, redirects[i + 1], REPLACE);
		else if (is_operator(redirects[i]) == RED_APPEND)
			output(process, redirects[i + 1], APPEND);
		i+=2;
	}
}

int	get_all_inputs(t_process *process)
{
	int		i;
	char	**redirects;

	i = 0;
	redirects = process->redirects;
	while (redirects[i])
	{
		if (is_operator(redirects[i]) == RED_INPUT)
			input(redirects[i + 1]);
		else if (is_operator(redirects[i]) == HERE_DOC && contain_heredoc(process))
			heredoc(redirects[i + 1]);
		i+=2;
	}
	if (ms.ignore)
	{
		close_heredoc_fd();
		return (false);
	}
	return (true);
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
			output(process, redirects[i + 1], REPLACE);
		else if (is_operator(redirects[i]) == RED_APPEND)
			output(process, redirects[i + 1], APPEND);
		i+=2;
	}
}
