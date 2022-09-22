#include "minishell.h"

t_minishell ms;



int main(int ac, char **av, char **env)
{
	char	*input;

	input = "echo 123456765 > file > dosya | deneme 123";
	ms.env = set_env(env);
	ms.paths = ft_split(get_env("PATH"), ':');
	ms.token = tokenize(input);
	// token_test();
	ms.commander = lexical_analysis();
	ms.last_cmd = ms.commander;
	ms.out_fd = 1;
	lexer_test();
	start_commander();

	// system("leaks a.out");
}
