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
		printf("Path Not Found !\n");
	file = ft_strjoin(paths[path], new_cmd);
	//printf("%s - %d - %s - %s\n", new_cmd, path, paths[path], file);
	execve(file, args, NULL);
}

/*
*	Eğer path üzerinde tek yol varsa
*	':' karakterinden split ile ayırt
*	edilemiyorsa kontrol edilecek.
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

	input = "ls -l -a -h";

	ms.env = set_env(env);
	ms.paths = ft_split(get_env("PATH"), ':');
	ms.token = tokenize(input);
	ms.commander = lexical_analysis();
	run_all_commands();

	// system("leaks a.out");
}
