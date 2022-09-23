#include "minishell.h"

t_minishell ms;

int main(int ac, char **av, char **env)
{
	char	*input;

	input = "cat << file | echo deneme";
	ms.env = set_env(env);
	ms.paths = ft_split(get_env("PATH"), ':');
	ms.token = tokenize(input);
	ms.commander = lexical_analysis();
	ms.in_fd = 0;
	ms.out_fd = 1;
	start_commander();

	// system("leaks a.out");
}
