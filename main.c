#include "minishell.h"

t_minishell ms;

void	free_paths()
{
	int	i;

	i = 0;
	while (ms.paths[i])
	{
		free(ms.paths[i]);
		i++;
	}
	free(ms.paths);
}

void	free_arrays(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_token()
{
	t_token	*token;

	token = ms.token;
	while (token->next)
		token = token->next;
	while (token)
	{
		free(token);
		token = token->prev;
	}
}

void	free_process()
{
	t_process	*process;

	process = ms.process;
	free_arrays(process->execute);
	free_arrays(process->redirects);
	while (process->next)
		process = process->next;
	while (process)
	{
		free(process);
		process = process->prev;
	}
}

void	free_app()
{
	free_token();
	free_process();
	free_paths();
}

void	init_shell(char *input, char **env)
{
	ms.process_count = 0;
	ms.token = NULL;
	ms.process = NULL;
	set_env(env);
	ms.paths = ft_split(get_env("PATH"), ':');
	tokenize(input);
	lexer();
	start_process();
}

int main(int ac, char **av, char **env)
{
	char	*input;
	char	*tmp;

	input = "echo deneme | cat << eof | grep bytes | ping google.com -c 5 > file | grep bytes | cat << eof";
	input = "cat << eof > file";
	init_shell(input, env);
	// input = "";
	// while (1)
	// {
	// 	tmp = input;
	// 	input = readline("\nminishell> ");
	// 	if (*tmp)
	// 		free(tmp);
	// 	if (!input)
	// 		break ;
	// 	init_shell(input, env);
	// 	add_history(input);
	// 	// free_app();
	// }

	// system("leaks a.out");
}
