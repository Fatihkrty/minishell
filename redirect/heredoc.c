/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scakmak <scakmak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 22:10:19 by fkaratay          #+#    #+#             */
/*   Updated: 2022/10/13 01:03:20 by scakmak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	close_heredoc(int sig)
{
	g_ms.ignore = TRUE;
	ioctl(STDIN_FILENO, TIOCSTI, "\n");
}

void	heredoc(char *endline)
{
	char		*input;
	static int	start = 0;

	if (start)
		close(g_ms.heredoc_fd[0]);
	start = 1;
	if (pipe(g_ms.heredoc_fd) < 0)
		return (perror("minishell"));
	while (1)
	{
		signal(SIGINT, &close_heredoc);
		input = readline("heredoc>> ");
		if (!input || ft_strcmp(input, endline) || g_ms.ignore)
		{
			free(input);
			break ;
		}
		write(g_ms.heredoc_fd[1], input, ft_strlen(input));
		write(g_ms.heredoc_fd[1], "\n", 1);
		free(input);
	}
	close(g_ms.heredoc_fd[1]);
}
