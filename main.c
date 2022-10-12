/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkaratay <fkaratay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 22:14:23 by fkaratay          #+#    #+#             */
/*   Updated: 2022/10/12 22:14:24 by fkaratay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_minishell ms;

void	init_env(char **env)
{
	ms.paths = NULL;
	set_env(env);
	set_paths();
}

void	init_shell(char *input, char **env)
{
	ms.token = NULL;
	ms.ignore = false;
	ms.process = NULL;
	ms.process_count = 0;
	tokenize(input);
	if (!lexer())
		return ;
	start_cmd();
}

void	ctrl_c(int sig)
{
	ms.ignore = true;
	ioctl(STDIN_FILENO, TIOCSTI, "\n");
	write(1, "\033[A", 3);
}

int main(int ac, char **av, char **env)
{
	char	*input;

	ms.parent_pid = getpid();
	init_env(env);
	while (ac && av)
	{
		signal(SIGINT, &ctrl_c);
		signal(SIGQUIT, SIG_IGN);
		printf("\033[32m");
		input = readline("minishell_> ");
		printf("\033[0m");
		fflush(stdout);
		if (!input)
		{
			printf("exit\n");
			free(input);
			break ;
		}
		if (ms.ignore)
		{
			ms.ignore = false;
			free(input);
			input = ft_calloc(sizeof(char *), 1);
		}
		if (*input)
		{
			init_shell(input, env);
			add_history(input);
			free_process();
		}
		free(input);
	}
	exit(errno);
}
