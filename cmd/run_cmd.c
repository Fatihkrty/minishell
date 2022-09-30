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
	t_process *process;

	process = ms.process;
	while (process)
	{
		close(process->fd[0]);
		close(process->fd[1]);
		process = process->next;
	}
}

void    run_cmd(t_process *cmd, int pos)
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
            if (cmd->prev == NULL)
                dup2(cmd->fd[1], 1);
            else if (cmd->next == NULL)
                dup2(cmd->prev->fd[0], 0);
            else
            {
                dup2(cmd->prev->fd[0], 0);
                dup2(cmd->fd[1], 1);
            }
            close_all_fd();
        }
		run_redirects(cmd);
		printf("Geldi\n");
     	execve(path, cmd->execute, NULL);
    }
	else
	{
		free(path);
		ms.pids[pos] = pid;
	}
}
