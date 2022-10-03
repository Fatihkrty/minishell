#include "../minishell.h"

void    token_test()
{
    t_token *token;

    token = ms.token;
    while(token)
	{
		printf("Token Str => [%s] Type: [%d] Len: [%zu]\n", token->str, token->type, ft_strlen(token->str));
		token = token->next;
	}
}

void    lexer_test()
{
    t_process *process;

    process = ms.process;
    while (process)
	{
		int c = 0;
		while (process->execute && process->execute[c])
		{
			printf("PROCESS ARGUMENTS: %s\n", process->execute[c]);
			c++;
		}
		printf("\n");
		c = 0;
		while (process->redirects && process->redirects[c])
		{
			printf("PROCESS REDIRECTS: %s\n", process->redirects[c]);
			c++;
		}
		printf("----------------------------------------\n");
		process = process->next;
	}
}
