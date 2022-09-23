#include "../minishell.h"

int get_args_len(char **args)
{
    char    **head;

    head = args;
    while (*args)
        args++;
    return (args - head);
}

void    red_output(t_commander *commander)
{
    int fd;
    int args_len;

    args_len = get_args_len(commander->arguments);
    if (args_len != 1)
    {
        printf("File args length error\n");
        return ;
    }
    fd = open(commander->arguments[0], O_CREAT | O_WRONLY | O_TRUNC, 0777);
    if (fd == -1)
        printf("Can not open file ! %d\n", fd);
    else
    {
        ms.out_fd = fd;
        printf("New out_fd value is: %d\n", ms.out_fd);
    }
}

void    check_command()
{
    t_commander *commander;

    commander = ms.commander;
    while (commander)
    {
        if (commander->type == RED_OUTPUT)
            red_output(commander);
        if (commander->type == PIPE)
            break;
        commander = commander->next;
    }

    commander = ms.commander;
    while (commander)
    {
        if (commander->type == STRING)
            run_cmd(commander->arguments);
        commander = commander->next;
    }
}



void    start_commander()
{
    t_commander *commander;

    check_command();
    // commander = ms.commander;
    // while (commander)
    // {
    //     commander = commander->next;
    // }
    
}