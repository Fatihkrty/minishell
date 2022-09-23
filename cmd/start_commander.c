#include "../minishell.h"

int get_args_len(char **args)
{
    char    **head;

    head = args;
    while (*args)
        args++;
    return (args - head);
}

void    red_output(t_commander *commander, int mode)
{
    int fd;
    int args_len;

    args_len = get_args_len(commander->arguments);
    if (args_len != 1)
    {
        printf("File args length error\n");
        return ;
    }
    if (mode == REPLACE)
        fd = open(commander->arguments[0], O_CREAT | O_WRONLY | O_TRUNC, 0777);
    else if (mode == APPEND)
        fd = open(commander->arguments[0], O_CREAT | O_WRONLY | O_APPEND, 0777);
    if (fd == -1)
        printf("Can not open file ! %d\n", fd);
    else
        ms.out_fd = fd;
}

void    red_input(t_commander *commander)
{
    int fd;

    fd = open(commander->arguments[0], O_RDONLY);
    if (fd == -1)
        printf("No such file ! %d\n", fd);
    else
        ms.in_fd = fd;

}

int check_endline(char *input, char *endline)
{
    int len;

    len = ft_strlen(endline);
    if (ft_strlen(input) == len)
        if (!ft_strncmp(input, endline, len))
            return (true);
    return (false);
}

void    red_heredoc(t_commander *commander)
{
    char    *tmp;
    char    *input;
    char    *result;
    char    *endline;

    input = NULL;
    tmp = input;
    result = "";
    endline = commander->arguments[0];
    while (1)
    {
        input = readline("heredoc>> ");
        if (check_endline(input, endline))
            break;
        input = ft_strjoin(input, "\n");
        tmp = result;
        result = ft_strjoin(result, input);
        free(input);
        if (*tmp)
            free(tmp);
    }
    printf("%s", result);
}

void    check_command()
{
    t_commander *commander;

    commander = ms.commander;
    while (commander)
    {
        if (commander->type == RED_OUTPUT)
            red_output(commander, REPLACE);
        else if (commander->type == RED_APPEND)
            red_output(commander, APPEND);
        else if (commander->type == RED_INPUT)
            red_input(commander);
        else if (commander->type == HERE_DOC)
            red_heredoc(commander);
        else if (commander->type == PIPE)
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