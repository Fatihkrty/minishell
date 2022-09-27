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

void    run_cmd(char **args, int *fd)
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
    if (pid == CHILD_PROCESS)
    {
        // printf("PROCESS: %s\n", *args);
        // printf("STDIN: %d\n", fd[0]);
        // printf("STDOUT: %d\n-------------\n", fd[1]);
        // close(fd[0]);
        printf("Process Olustu: %s\n", *args);
		dup2(ms.fd[1], 1);
		dup2(ms.fd[0], 0);
		close(ms.fd[0]);
		close(ms.fd[1]);
        execve(path, args, NULL);
        exit(1);
    }
    // close(fd[1]);
    // wait(NULL);
    // dup2(fd[0], 0);
    // close(fd[0]);
    // char str[2000];
    // read(fd[0], str, 2000);
    // close(fd[0]);
    // str[2000] = 0;
    // printf("%s\n", str);
}
