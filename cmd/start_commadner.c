#include "../minishell.h"

void    check_command(t_commander *commander)
{

}

void    start_commander()
{
    t_commander *commander;

    commander = ms.commander;
    while (commander)
    {
        check_command(commander);
        commander = commander->next;
    }
    
}