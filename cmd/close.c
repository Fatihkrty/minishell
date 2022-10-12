/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkaratay <fkaratay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:56:52 by fkaratay          #+#    #+#             */
/*   Updated: 2022/10/12 19:51:24 by fkaratay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	close_all_fd(void)
{
	t_process	*process;

	process = ms.process;
	while (process)
	{
		close(process->fd[0]);
		close(process->fd[1]);
		process = process->next;
	}
}

void	close_heredoc_fd(void)
{
	close(ms.heredoc_fd[0]);
	close(ms.heredoc_fd[1]);
}
