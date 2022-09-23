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
    // printf("Run cmd is start. out_fd: %d\n", ms.out_fd);
    pid = fork();
    if (pid == -1)
        printf("Process fork error !\n");
    else if (pid == CHILD_PROCESS)
    {
        printf("Fork created\n");
        dup2(ms.out_fd, 1);
        dup2(ms.in_fd, 0);
        execve(path, args, NULL);
    }
    else
        wait(NULL);
}
