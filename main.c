#include "minishell.h"

t_minishell ms;

void	init_shell(char *input, char **env)
{
	ms.process_count = 0;
	ms.token = NULL;
	ms.env = set_env(env);
	ms.paths = ft_split(get_env("PATH"), ':');
	tokenize(input);
	lexer();
	start_process();
}

int main(int ac, char **av, char **env)
{
	char	*input;

	input = "cat << file";
	init_shell(input, env);

	// system("leaks a.out");
}
