#include "../minishell.h"

void    command_err()
{
    errno = 127;
    write(2, "minishell: Command not found\n", 29);
    if (!is_parent())
        exit(errno);
}

void    token_err()
{
    errno = 258;
    write(2, "minishell: Unexpected Token\n", 28);
    if (!is_parent())
        exit(errno);
}

void    directory_err()
{
    errno = 126;
	write(2, "minishell : is a directory\n", 27);
	if (!is_parent())
        exit(errno);
}

void	no_file_err()
{
	errno = 1;
	write(2, "minishell : No such file or directory\n", 39);
	if (!is_parent())
        exit(errno);
}
