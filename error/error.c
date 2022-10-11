#include "../minishell.h"

void    command_err(char *str)
{
    errno = 127;
	write(2, "minishell: ", 11);
	write(2, str, ft_strlen(str));
	write(2, ": command not found\n", 20);
    if (!is_parent())
        exit(errno);
}

void    token_err()
{
    errno = 258;
    write(2, "minishell: syntax error near unexpected token\n", 46);
}

void    directory_err(char *str)
{
    errno = 126;
	write(2, "minishell: ", 11);
	write(2, str, ft_strlen(str));
	write(2, ": is a directory\n", 17);
	if (!is_parent())
        exit(errno);
}

void	no_file_err(char *str)
{
	errno = 1;
	write(2, "minishell: ", 11);
	write(2, str, ft_strlen(str));
	write(2, ": No such file or directory\n", 28);
	if (!is_parent())
        exit(errno);
}
