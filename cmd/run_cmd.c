#include "../minishell.h"


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
        run_redirects(process, false);
        execve(path, process->execute, NULL);
    }
	else
	{
		free(path);
		process->pid = pid;
	}
}
