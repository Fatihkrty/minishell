/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkaratay <fkaratay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:15:09 by fkaratay          #+#    #+#             */
/*   Updated: 2022/10/12 20:44:03 by fkaratay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	pipe_route(t_process *process)
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

void	heredoc_route(t_process *process)
{
	dup2(ms.heredoc_fd[0], 0);
	if (ms.process_count > 1 && process->next != NULL)
		dup2(process->fd[1], 1);
	set_all_outputs(process);
}

void	cmd_route(t_process *process)
{
	if (ms.process_count > 1)
		pipe_route(process);
	get_all_inputs(process);
	set_all_outputs(process);
}

void	run_cmd(t_process *process)
{
	pid_t	pid;
	char	*path;

	if (!get_all_inputs(process))
	{
		ms.ignore = false;
		return ;
	}
	pid = fork();
	if (pid == CHILD_PROCESS)
	{
		if (contain_heredoc(process))
			heredoc_route(process);
		else
			cmd_route(process);
		run_builtin(process->execute);
		path = get_path(process->execute[0]);
		execve(path, process->execute, ms.env);
		command_err(process->execute[0]);
		exit(errno);
	}
	else
		process->pid = pid;
}
