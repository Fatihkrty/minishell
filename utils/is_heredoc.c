#include "../minishell.h"

int contain_heredoc(t_process *process)
{
    int i;

    i = 0;
    while (process->redirects[i])
    {
        if(is_operator(process->redirects[i]) == HERE_DOC)
            return (true);
        i++;
    }
    return (false);
}
