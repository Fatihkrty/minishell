/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkaratay <fkaratay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 22:14:23 by fkaratay          #+#    #+#             */
/*   Updated: 2022/10/13 04:41:12 by fkaratay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_minishell	g_ms;

void	init_app(char **env)
{
	errno = 0;
	g_ms.paths = NULL;
	g_ms.parent_pid = getpid();
	set_env(env);
	set_paths();
}

void	init_shell(char *input, char **env)
{
	g_ms.token = NULL;
	g_ms.ignore = FALSE;
	g_ms.process = NULL;
	g_ms.process_count = 0;
	tokenize(input);
	if (!lexer())
		return ;
	start_cmd();
	free_process();
}

void	ctrl_c(int sig)
{
	g_ms.ignore = TRUE;
	ioctl(STDIN_FILENO, TIOCSTI, "\n");
	write(1, "\033[A", 3);
}

void	ctrl_d(char *input)
{
	if (!input)
	{
		printf("exit\n");
		exit(errno);
	}
}

int	main(int ac, char **av, char **env)
{
	char	*input;

	init_app(env);
	while (ac && av)
	{
		signal(SIGINT, &ctrl_c);
		signal(SIGQUIT, SIG_IGN);
		write(1, "\033[32m", 5);
		input = readline("minishell_> ");
		write(1, "\033[0m", 4);
		ctrl_d(input);
		if (g_ms.ignore)
		{
			g_ms.ignore = FALSE;
			free(input);
			input = ft_calloc(sizeof(char *), 1);
		}
		if (*input)
		{
			init_shell(input, env);
			add_history(input);
		}
		free(input);
	}
	exit(errno);
}
