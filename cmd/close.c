/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkaratay <fkaratay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:56:52 by fkaratay          #+#    #+#             */
/*   Updated: 2022/10/13 13:53:48 by fkaratay         ###   ########.fr       */
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
	if (g_ms.heredoc_fd[0] > 2)
		close(g_ms.heredoc_fd[0]);
	if (g_ms.heredoc_fd[1] > 2)
		close(g_ms.heredoc_fd[1]);
}
