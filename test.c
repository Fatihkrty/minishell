#include "minishell.h"

void    token_test()
{
    t_token *token;

    token = ms.token;
    while(token)
	{
		printf("String: %s Type: %d Len: %zu\n", token->str, token->type, ft_strlen(token->str));
		token = token->next;
	}
}

void    lexer_test()
{
    t_commander *commander;

    commander = ms.commander;
    while (commander)
	{
		int c = 0;
		printf("COMMANDER COMMAND: %s LEN: %zu TYPE: %d\n", commander->command, ft_strlen(commander->command), commander->type);
		while (commander->arguments[c])
		{
			printf("COMMANDER ARGMENTS: %s\n", commander->arguments[c]);
			c++;
		}
		printf("\n");
		commander = commander->next;
	}
}
