#include "../minishell.h"

static int check_endline(char *input, char *endline)
{
	int len;

	if(!input)
		return (true);
	len = ft_strlen(endline);
	if (ft_strlen(input) == len)
		if (!ft_strncmp(input, endline, len))
			return (true);
	return (false);
}

void	close_heredoc(int sig)
{
	ms.status = 257;
	ioctl(STDIN_FILENO, TIOCSTI, "\n");
}

void	red_heredoc(char *endline)
{
	char	*input;

	if (pipe(ms.heredoc_fd) < 0)
		return perror("minishell");
	while (ms.status != 257)
	{
		signal(SIGINT, &close_heredoc);
		input = readline("heredoc>> ");
		if (check_endline(input, endline))
		{
			free(input);
			break ;
		}
		write(ms.heredoc_fd[1], input, ft_strlen(input));
		write(ms.heredoc_fd[1], "\n", 1);
		free(input);
	}
	close(ms.heredoc_fd[1]);
}
