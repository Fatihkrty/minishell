#include "../minishell.h"

char    *get_path(char *cmd)
{
    char    *path;
    char    **paths;
    char    *new_cmd;

    paths = ms.paths;
    new_cmd = ft_strjoin("/", cmd);
    while (*paths)
    {
        path = ft_strjoin(*paths, new_cmd);
        if (!access(path, F_OK))
        {
            free(new_cmd);
            return (path);
        }
        free(path);
        paths++;
    }
    free(new_cmd);
    return (NULL);
}

void    run_cmd(char **args)
{
    int     pid;
    char    *path;

    path = get_path(*args);
    if (!path)
	{
		perror("PATH ERROR");
		return ;
	}
    pid = fork();
    if (pid == -1)
	{
        perror("FORK ERROR");
		return ;
	}
    else if (pid == CHILD_PROCESS)
    {
        dup2(ms.in_fd, 0);
        dup2(ms.out_fd, 1);
        execve(path, args, NULL);
        exit(0);
    }
	else
		wait(NULL);
}
