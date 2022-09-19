#include "minishell.h"
#include "./lexer/lexer.h"

t_minishell ms;

int	get_path(char *command)
{
	int		i;
	char	*path;
	char	**path_arr;

	i = 0;
	path_arr = ms.paths;
	while (path_arr[i])
	{
		path = ft_strjoin(path_arr[i], command);
		if (!access(path, F_OK))
		{
			free(path);
			return (i);
		}
		free(path);
		i++;
	}
	return (-1);
}

void	run_cmd(char *file, char **args)
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		sleep(4);
		execve(file, args, NULL);
	}
	wait(NULL);
	printf("Main process");

	
}

void	run_commands(char *command, char **args)
{
	int		path;
	char	**paths;
	char	*new_cmd;
	char	*file;

	paths = ms.paths;
	new_cmd = ft_strjoin("/", command);
	path = get_path(new_cmd);

	// TODO Error Fırlatılacak
	if (path == -1)
	{
		printf("Path Not Found !\n");
		return ;
	}
	file = ft_strjoin(paths[path], new_cmd);
	free(new_cmd);
	run_cmd(file, args);
	free(file);
}

/*
*	Eğer path üzerinde tek yol varsa
*	':' karakterinden split ile ayırt
*	edilemiyorsa kontrol edilecek.
*	@param void
*	@return non-return
*/
void	run_all_commands()
{
	t_commander	*commander;

	commander = ms.commander;
	while (commander)
	{
		run_commands(commander->command, commander->arguments);
		commander = commander->next;
	}
}

int main(int ac, char **av, char **env)
{
	char	*input;

	// input = "lssds";
	input = "echo \"den\"\"e\"\"me\"";

	ms.env = set_env(env);
	ms.paths = ft_split(get_env("PATH"), ':');
	ms.token = tokenize(input);
	// token_test();
	ms.commander = lexical_analysis();
	// lexer_test();
	run_all_commands();

	// system("leaks a.out");
}

