#include "minishell.h"

t_minishell ms;

int main(int ac, char **av, char **env)
{
	char	*input;

	input = "cat<as abc \"m\"e\"r\''\'ha'ba\"\"l\"\"'\"\"s\"ls|grep as > dosya file2 | ls -la < deneme < abcacb";
	ms.env = set_env(env);
	ms.paths = ft_split(get_env("PATH"), ':');
	ms.token = tokenize(input);
	token_test();
	lexical_analysis();
	lexer_test();
	ms.in_fd = 0;
	ms.out_fd = 1;
	start_commander();

	// system("leaks a.out");
}
