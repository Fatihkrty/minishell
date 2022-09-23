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
	char		**args;
	char		**tmp;
	t_token		*token;
	t_commander	*commander;
	t_commander	*last_commander;

	args = NULL;
	commander = NULL;
	token = ms.token;
	while (token)
	{
		if (token->type == PIPE || token->prev == NULL)
		{
			if (token->type == PIPE)
				token = token->next;
			args = init_arg_arr();
			last_commander = commander_addback(&commander, init_commander(clean_quote(token), token->type));
		}
		tmp = args;
		args = arg_arr_push(args, clean_quote(token));
		free(tmp);
		last_commander->arguments = args;
		token = token->next;
	}
	return (commander);
}
