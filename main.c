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
	errno = 0;
	ms.status = 0;
	ms.token = NULL;
	ms.process = NULL;
	ms.process_count = 0;
	tokenize(input);
	if (!lexer())
		return ;
	start_cmd();
}

void	ctrl_c(int sig)
{
	// printf("\nFirst: %lu\n", ms.termios_p.c_iflag);
	// ms.termios_p.c_iflag = IXOFF;
	// printf("Last: %lu\n", ms.termios_p.c_iflag);
	tcflush(STDIN_FILENO, TCIFLUSH);
	// tcsetattr(STDIN_FILENO, TCSANOW, &(ms.termios_p));
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
		tcgetattr(STDIN_FILENO, &ms.termios_p);
		signal(SIGINT, &ctrl_c);
		printf("TTY: %d\n", isatty(STDIN_FILENO));
		printf("NAME: %s\n", ttyname(STDIN_FILENO));
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
			free_process();
		}
		free(input);
	}
	// system("leaks a.out");
	exit(ms.status);
}
