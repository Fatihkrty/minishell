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
	ms.process = NULL;
	ms.process_count = 0;
	tokenize(input);
	lexer();
	start_cmd();
}

void	ctrl_c(int sig)
{
	// ioctl(STDIN_FILENO, TIOCSTI, "\n"); // input output devicelere inject yapmak için
	// write(1, "\033c", 2);
	// write(1, "\r", 1);
	// write(1, "\033[B\033[2K", 7);

	write(1, "\033[B", 3); // alt satır
	write(1, "\033[1L", 4); // imleci başa getir
	// write(1, "\033[1K\r", 5); // tüm ekranı sil ve satırbaşına geç
	write(1, "minishell> ", 11);
	// fflush(stdin);
}

int main(int ac, char **av, char **env)
{
	char	*input;
	char	*tmp;

	ms.parent_pid = getpid();
	init_env(env);
	while (ac && av)
	{
		signal(SIGINT, &ctrl_c);
		input = readline("\033[34mminishell> \033[0m");
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
