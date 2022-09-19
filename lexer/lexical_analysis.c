#include "lexer.h"
#include "../minishell.h"

/*
** Norminette için kullanılacak
** Değişkenleri lexer.h içerisinde

void	init_variables(t_lexer *lex)
{
	lex->token = ms.token;
	lex->is_command = true;
	lex->args = NULL;
	lex->commander = NULL;
}
*/
t_commander	*lexical_analysis()
{
	int			is_command;
	char		*data;
	char		**args;
	char		**tmp;
	t_token		*token;
	t_commander	*commander;
	t_commander	*last_commander;

	token = ms.token;
	is_command = true;
	args = NULL;
	commander = NULL;
	while (token)
	{
		if (token->type == STRING)
			data = clean_quote(token->str);
		else
			data = token->str;
		if (is_command)
		{
			args = init_arg_arr();
			last_commander = commander_addback(&commander, init_commander(data, token->type));
		}
		if (token->type != PIPE)
		{
			tmp = args;
			args = arg_arr_push(args, data);
			free(tmp);
			last_commander->arguments = args;
		}
		is_command = false;
		if (token->type == PIPE)
			is_command = true;
		token = token->next;
	}
	return (commander);
}
