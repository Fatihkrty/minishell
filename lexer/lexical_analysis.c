#include "lexer.h"
#include "../minishell.h"

void	init_variables(t_lexer *lex)
{
	lex->token = ms.token;
	lex->is_command = true;
	lex->args = NULL;
	lex->commander = NULL;
}

void	lexical_analysis()
{
	t_lexer	lex;

	init_variables(&lex);
	while (lex.token)
	{
		if (lex.token->type == STRING)
			lex.data = clean_quote(lex.token->str);
		else
			lex.data = lex.token->str;
		if (lex.is_command)
		{
			lex.args = init_arg_arr();
			lex.last_commander = commander_addback(&lex.commander, init_commander(lex.data));
		}
		arg_arr_push(&lex.args, lex.data);
		lex.last_commander->arguments = lex.args;
		lex.is_command = false;
		if (lex.token->type == PIPE)
			lex.is_command = true;
		lex.token = lex.token->next;
	}
	ms.commander = lex.commander;
	while (lex.commander)
	{
		int c = 0;
		printf("COMMANDER COMMAND: %s\n", lex.commander->command);
		while (lex.commander->arguments[c])
		{
			printf("COMMANDER ARGMENTS: %s\n", lex.commander->arguments[c]);
			c++;
		}
		lex.commander = lex.commander->next;
	}
}
