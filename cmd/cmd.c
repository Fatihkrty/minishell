/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scakmak <scakmak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:58:46 by fkaratay          #+#    #+#             */
/*   Updated: 2022/10/13 01:03:20 by scakmak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	check_builtin(t_process *process)
{
	int	in;
	int	out;

	in = dup(0);
	out = dup(1);
	get_all_inputs(process);
	set_all_outputs(process);
	run_builtin(process->execute);
	dup2(in, 0);
	dup2(out, 1);
	close(in);
	close(out);
}

void	wait_cmd(void)
{
	t_process	*process;

	process = g_ms.process;
	if (contain_heredoc(process))
		close_heredoc_fd();
	close_all_fd();
	while (process)
	{
		waitpid(process->pid, &errno, 0);
		errno = WEXITSTATUS(errno);
		process = process->next;
	}
}

void	start_cmd(void)
{
	t_process	*process;

	process = g_ms.process;
	if (!process)
		return ;
	if (is_builtin(process->execute[0]) && g_ms.process_count == 1)
	{
		check_builtin(process);
		process = process->next;
	}
	while (process)
	{
		run_cmd(process);
		process = process->next;
	}
	wait_cmd();
}
