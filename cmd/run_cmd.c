#include "../minishell.h"

void    pipe_route(t_process *process)
{
    if (process->prev == NULL)
        dup2(process->fd[0], 0);
    else if (process->next == NULL)
        dup2(process->prev->fd[0], 0);
    else
    {
        dup2(process->prev->fd[0], 0);
        dup2(process->fd[1], 1);
    }
    close_all_fd();
}

void	route_heredoc(t_process *process)
{
	dup2(ms.heredoc_fd[0], 0);
	if (ms.process_count > 1 && process->next != NULL)
		dup2(process->fd[1], 1);
	set_all_outputs(process);
}

void	route_cmd(t_process *process)
{
	if (ms.process_count > 1)
		pipe_route(process);
	run_redirects(process);
}

void    run_cmd(t_process *process)
{
    pid_t   pid;
    char    *path;
    int     builtin_type;

	if (is_heredoc(process))
		get_all_inputs(process);
	if (ms.status == -1)
	{
		close_heredoc_fd();
		return ;
	}
    pid = fork();
    if (pid == CHILD_PROCESS)
    {
		if (is_heredoc(process))
			route_heredoc(process);
		else
			route_cmd(process);
        builtin_type = is_builtin(process->execute[0]);
        if (builtin_type)
            run_builtin(process->execute, builtin_type);
        else
        {
			close_heredoc_fd();
		    path = get_path(process->execute[0]);
            execve(path, process->execute, ms.env);
            free(path);
			exit(-1);
        }
        exit(builtin_type);
    }
	else
		process->pid = pid;
}
