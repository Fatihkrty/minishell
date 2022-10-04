#include "../minishell.h"


void    run_cmd(t_process *process)
{
    pid_t   pid;
    char    *path;
    int     status;

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
        status = execve(path, process->execute, ms.env);
        free(path);
        exit(status);
    }
	else
	{
		free(path);
		process->pid = pid;
	}
}
