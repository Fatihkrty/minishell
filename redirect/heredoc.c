#include "../minishell.h"

void	close_heredoc(int sig)
{
	ms.ignore = true;
	ioctl(STDIN_FILENO, TIOCSTI, "\n");
}

void	heredoc(char *endline)
{
	char		*input;
	static int	start = 0;

	if (start)
		close(ms.heredoc_fd[0]);
	start = 1;
	if (pipe(ms.heredoc_fd) < 0)
		return perror("minishell");
	while (1)
	{
		signal(SIGINT, &close_heredoc);
		input = readline("heredoc>> ");
		if (!input || ft_strcmp(input, endline) || ms.ignore)
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
