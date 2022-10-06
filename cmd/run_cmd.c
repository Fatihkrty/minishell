#include "../minishell.h"

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

void    pipe_route(t_process *process)
{
    if (process->prev == NULL)
        dup2(process->fd[1], 1);
    else if (process->next == NULL)
        dup2(process->prev->fd[0], 0);
    else
    {
        dup2(process->prev->fd[0], 0);
        dup2(process->fd[1], 1);
    }
    close_all_fd();
}


void    run_cmd(t_process *process)
{
    pid_t   pid;
    char    *path;
    int     status;

    pid = fork();
    if (pid == -1)
        return perror("minishell");
    if (pid == CHILD_PROCESS)
    {
        if (ms.process_count > 1)
            pipe_route(process);
        run_redirects(process);
		path = get_path(process->execute[0]);
        status = execve(path, process->execute, ms.env);
        free(path);
        exit(status);
    }
	else
		process->pid = pid;
}
