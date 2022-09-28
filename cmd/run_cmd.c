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

void    close_all_fd()
{
    t_pipes *pipes;

    pipes = ms.pipes;
	while (pipes->next)
	{
		close(pipes->fd[0]);
		close(pipes->fd[1]);
		pipes = pipes->next;
	}
}

void    run_cmd(t_commander *cmd, t_pipes *pipes)
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
    if (pid == -1)
    {
        perror("FORK ERROR");
        return ;
    }
    if (pid == CHILD_PROCESS)
    {
        if (ms.process_count > 1)
        {
            if (pipes->prev == NULL)
                dup2(pipes->fd[1], 1);
            else if (pipes->next == NULL)
                dup2(pipes->prev->fd[0], 0);
            else
            {
                dup2(pipes->prev->fd[0], 0);
                dup2(pipes->fd[1], 1);
            }
            close_all_fd();
        }
        execve(path, cmd->execute, NULL);
    }
}
