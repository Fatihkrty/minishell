#include "../minishell.h"


t_commander *lexical_analysis()
{
	char		**tmp;
	char		**red;
	char		**args;
	t_token		*token;
	t_commander	*commander;

	token = ms.token;
	while (token)
	{
		if (token->type == PIPE || token->prev == NULL)
		{
			if (token->type == PIPE)
				token = token->next;
			args = init_args();
			red = init_args();
			commander = init_commander();
			commander_addback(&ms.commander, commander);
		}
		if (token->type == STRING)
			args = push_args(args, clean_quote(token->str));
		else
		{
			red = push_args(red, token->str);
			token = token->next;
			if (token)
				red = push_args(red, token->str);
		}
		commander->arguments = args;
		commander->red = red;
		if (token)
			token = token->next;
	}
	return (commander);
}
