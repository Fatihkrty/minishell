#include "../minishell.h"

void    command_err()
{
    write(2, "minishell: Command not found\n", 29);
    errno = -1;
    if (is_parent())
        return ;
    else
        exit(errno);
}

void    token_err()
{
    write(2, "minishell: Unexpected Token\n", 28);
    errno = -1;
    if (is_parent())
        return ;
    else
        exit(errno);
}

void    directory_err()
{
    errno = 21;
    perror("minishell");
    exit(errno);
}