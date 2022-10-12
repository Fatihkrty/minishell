/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkaratay <fkaratay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 22:10:49 by fkaratay          #+#    #+#             */
/*   Updated: 2022/10/12 22:11:21 by fkaratay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	input(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (is_parent())
	{
		if (fd == -1)
		{
			ms.ignore = true;
			return (no_file_err(file));
		}
		if (ms.heredoc_fd[0] != 0)
			dup2(fd, ms.heredoc_fd[0]);
	}
	else
	{
		if (fd == -1)
			no_file_err(file);
		dup2(fd, 0);
	}
	close(fd);
}
