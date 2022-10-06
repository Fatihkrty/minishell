#include "minishell.h"

t_minishell ms;

void	init_shell(char *input, char **env)
{
	ms.token = NULL;
	ms.process = NULL;
	ms.process_count = 0;
	tokenize(input);
	lexer();
	start_cmd();
}

void	ctrl_c(int sig)
{
	// write(1, "\033c", 2);
	// write(1, "\r", 1);
	// write(1, "\033[B\033[2K", 7);

	// write(0, "\033[1K\r", 5); // tüm ekranı sil ve satırbaşına geç
	// sleep(1);
	// printf("minishell> ");
	// write(0, "minishell> ", 11);
	// fflush(stdin);
	// write(1, "\033[H", 3);
	// sleep(1);
	// write(0, "\033[B", 3); // alt satır
	// sleep(1);
	// write(0, "\033[1L", 4); // imleci başa getir
	// sleep(1);
	// write(1, "\n", 1);
	// write(1, "minishell> ", 12);
	// fflush(stdin);
	// char a = 8;
	// write(0, &a, 1);
	// readline("minishell> ");
	// sleep(1);
	// write(1, "\033[1D", 4);
	// int a = 10;
	// write(0, "\r\n", 2);
	// close(0);
	// printf("minishell> \n");

	// if (!is_parent())
	// 	write(1, "\n", 1);
	// else
	// 	close(STDIN_FILENO);
}

int main(int ac, char **av, char **env)
{
	char	*input;
	char	*tmp;

	ms.parent_pid = getpid();
	set_env(env);
	ms.paths = ft_split(get_env("PATH"), ':');
	// signal(SIGINT, &ctrl_c);
	while (ac && av)
	{
		input = readline("minishell> ");
		if (!input)
		{
			printf("exit\n");
			free(input);
			break ;
		}
		if (*input)
		{
			init_shell(input, env);
			add_history(input);
			free_app();
		}
		free(input);
	}
	exit(ms.status);
	// system("leaks a.out");
}
