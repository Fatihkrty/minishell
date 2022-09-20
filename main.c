#include "minishell.h"
#include "./lexer/lexer.h"

t_minishell ms;

char	*get_path(char *command)
{
	int		i;
	char	*path;
	char	*new_cmd;
	char	**path_arr;

	i = 0;
	path_arr = ms.paths;
	new_cmd = ft_strjoin("/", command);
	while (path_arr[i])
	{
		path = ft_strjoin(path_arr[i], new_cmd);
		if (!access(path, F_OK))
		{
			free(new_cmd);
			return (path);
		}
		free(path);
		i++;
	}
	free(new_cmd);
	return (NULL);
}

void	run_cmd(char *file, char **args)
{
	int	pid;

	pid = fork();
	if (pid == CHILD_PROCESS)
	{
		execve(file, args, NULL);
	}
	else
		wait(NULL);
}

void	run_commander(t_commander *commander)
{
	char	*path;

	path = get_path(commander->command);
	if (!path)
	{
		// TODO Error Fırlatılacak
		perror("ERROR");
		return ;
	}
	if (commander->type = STRING)
		run_cmd(path, commander->arguments);
	free(path);
}

/*
*	Eğer path üzerinde tek yol varsa
*	':' karakterinden split ile ayırt
*	edilemiyorsa kontrol edilecek.
*/
void	start_commander()
{
	t_commander	*commander;

	commander = ms.commander;
	while (commander)
	{
		run_commander(commander);
		commander = commander->next;
	}
}

int main(int ac, char **av, char **env)
{
	char	*input;

	// input = "lssds";
	input = "ls -l -a -h > file";
	// input = "cat > file.txt";

	ms.env = set_env(env);
	ms.paths = ft_split(get_env("PATH"), ':');
	ms.token = tokenize(input);
	// token_test();
	ms.commander = lexical_analysis();
	// lexer_test();
	start_commander();

	// system("leaks a.out");
}

