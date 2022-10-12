/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scakmak <scakmak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:56:52 by fkaratay          #+#    #+#             */
/*   Updated: 2022/10/13 01:03:20 by scakmak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	close_all_fd(void)
{
	t_process	*process;

	process = g_ms.process;
	while (process)
	{
		close(process->fd[0]);
		close(process->fd[1]);
		process = process->next;
	}
}

void	close_heredoc_fd(void)
{
	close(g_ms.heredoc_fd[0]);
	close(g_ms.heredoc_fd[1]);
}
