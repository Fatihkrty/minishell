#include "minishell.h"

t_minishell ms;

void	init_env(char **env)
{
	ms.paths = NULL;
	set_env(env);
	set_paths();
}

void	init_shell(char *input, char **env)
{
	ms.status = 0;
	ms.token = NULL;
	ms.process = NULL;
	ms.process_count = 0;
	tokenize(input);
	lexer();
	start_cmd();
}

void	ctrl_c(int sig)
{
	ioctl(STDIN_FILENO, TIOCSTI, "\n");
	write(1, "\033[A", 3);
}

int main(int ac, char **av, char **env)
{
	char	*input;

	ms.parent_pid = getpid();
	init_env(env);
	while (ac && av)
	{
		signal(SIGINT, &ctrl_c);
		input = readline("\033[34mminishell> \033[0m");
		if (!input)
		{
			printf("exit\n");
			free(input);
			break ;
		}
		if (*input)
		{
			init_shell(input, env);
			add_history(input);
			free_app();
		}
		free(input);
	}
	exit(ms.status);
}
