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

void close_all_fd()
{
    t_fd_router *router;

    router = ms.router;
	while (router->next)
	{
        // printf("File Closed: %d\n", router->fd[0]);
        // printf("File Closed: %d\n", router->fd[1]);
		close(router->fd[0]);
		close(router->fd[1]);
		router = router->next;
	}
}

void    run_cmd(t_commander *cmd, t_fd_router *router)
{
    int     pid;
    char    *path;

    path = get_path(*(cmd->execute));
    if (!path)
	{
		perror("PATH ERROR");
		return ;
	}
    pid = fork();
    if (pid == CHILD_PROCESS)
    {
        if (router->prev == NULL)
        {
            printf("Process one: %s\n", *(cmd->execute));
            dup2(router->fd[1], 1);
            close_all_fd();
            execve(path, cmd->execute, NULL);
        }
        else if (router->next == NULL)
        {
            printf("Process Last Str: %s\n", *(cmd->execute));
            dup2(router->prev->fd[0], 0);
            close_all_fd();
            execve(path, cmd->execute, NULL);
        }
        else
        {
            printf("Process two: %s\n", *(cmd->execute));
            dup2(router->prev->fd[0], 0);
            dup2(router->fd[1], 1);
            close_all_fd();
            execve(path, cmd->execute, NULL);
        }
    }
    // close_all_fd();

}
