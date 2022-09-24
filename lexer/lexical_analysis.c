#include "../minishell.h"

t_commander *lexical_analysis()
{
	char **args;
	char **tmp;
	t_token *token;
	t_commander *commander;
	t_commander *last_commander;

	commander = NULL;
	token = ms.token;
	while (token)
	{
		if (token->type != COMMAND || token->prev == NULL)
		{
			args = init_arg_arr();
			last_commander = commander_addback(&commander, init_commander(clean_quote(token), token->type));
		}
		if (token->type == COMMAND)
		{
			tmp = args;
			args = arg_arr_push(args, clean_quote(token));
			free(tmp);
			last_commander->arguments = args;
		}
		token = token->next;
	}
	return (commander);
}
