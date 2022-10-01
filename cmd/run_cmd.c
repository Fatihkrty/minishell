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

void    run_cmd(t_process *process)
{
    pid_t   pid;
    char    *path;

    path = get_path(process->execute[0]);
    if (!path)
		return perror("PATH ERROR");
    pid = fork();
    if (pid == -1)
        return perror("FORK ERROR");
    if (pid == CHILD_PROCESS)
    {
        if (ms.process_count > 1)
            pipe_route(process);
        run_redirects(process);
        execve(path, process->execute, NULL);
    }
	else
	{
		free(path);
		process->pid = pid;
	}
}
