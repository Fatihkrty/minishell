#include "minishell.h"

t_minishell ms;

int main(int ac, char **av, char **env)
{
	char	*input;

	input = "ping -c 5 google.com | grep bytes";
	ms.process_count = 0;
	ms.env = set_env(env);
	ms.paths = ft_split(get_env("PATH"), ':');
	ms.token = tokenize(input);
	lexical_analysis();
	ms.in_fd = 0;
	ms.out_fd = 1;
	start_commander();

	// system("leaks a.out");
}
