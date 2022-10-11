#include "../minishell.h"

void	free_token()
{
	t_token	*token;
    t_token *tmp;

	token = ms.token;
    while (token)
    {
        free(token->str);
        token = token->next;
    }
	token = ms.token;
	while (token)
    {
        tmp = token;
        token = token->next;
        free(tmp);
    }
}