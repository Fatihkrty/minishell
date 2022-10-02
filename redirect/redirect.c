#include "../minishell.h"


void	run_redirects(t_process *process, int heredoc)
{
	int		i;
	char	**redirects;

	i = 0;
	redirects = process->redirects;
	while (redirects[i])
	{
		if (is_operator(process->redirects[i]) == RED_OUTPUT)
			red_output(process->redirects[i + 1], REPLACE);
		else if (is_operator(process->redirects[i]) == RED_APPEND)
			red_output(process->redirects[i + 1], APPEND);
		else if (is_operator(process->redirects[i]) == RED_INPUT)
			red_input(process->redirects[i + 1]);
		else if (is_operator(process->redirects[i]) == HERE_DOC && heredoc)
			red_heredoc(process->redirects[i + 1]);
		i++;
	}
}


char	*get_endline(char **redirects)
{
	int	i;

	i = 0;
	while (redirects[i])
	{
		if (is_operator(redirects[i]) == HERE_DOC)
			return (redirects[i + 1]);
		i++;
	}
	return (NULL);
}
