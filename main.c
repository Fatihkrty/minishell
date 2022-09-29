#include "minishell.h"

t_minishell ms;

void	init_shell(char *input, char **env)
{
	ms.process_count = 0;
	ms.env = set_env(env);
	ms.paths = ft_split(get_env("PATH"), ':');
	ms.token = tokenize(input);
	lexical_analysis();
	// lexer_test();
	start_process();
}

int main(int ac, char **av, char **env)
{
	char	*input;

	input = "ping -c 5 google.com | grep 'rtt' | ls -l | grep minishell";
	init_shell(input, env);

	// system("leaks a.out");
}
