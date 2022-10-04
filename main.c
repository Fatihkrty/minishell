#include "minishell.h"

t_minishell ms;

void	init_shell(char *input, char **env)
{
	ms.token = NULL;
	ms.process = NULL;
	ms.process_count = 0;
	tokenize(input);
	lexer();
	start_cmd();
}

int main(int ac, char **av, char **env)
{
	char	*input;
	char	*tmp;

	ms.parent_pid = getpid();
	input = "";
	set_env(env);
	ms.paths = ft_split(get_env("PATH"), ':');
	while (ac && av)
	{
		input = readline("minishell> ");
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
	// system("leaks a.out");
}
