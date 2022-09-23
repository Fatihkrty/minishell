#include "minishell.h"

t_minishell ms;

int main(int ac, char **av, char **env)
{
	char	*input;

	input = "ls > file | echo deneme";
	ms.env = set_env(env);
	ms.paths = ft_split(get_env("PATH"), ':');
	ms.token = tokenize(input);
	// token_test();
	ms.commander = lexical_analysis();
	ms.out_fd = 1;
	ms.in_fd = 0;
	// lexer_test();
	start_commander();

	// system("leaks a.out");
}
