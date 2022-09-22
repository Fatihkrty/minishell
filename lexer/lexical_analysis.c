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

// void	set_commander(t_token *token)
// {
// 	char		*args;
// 	char		*str;
// 	t_commander	*last_commander;

// 	args = init_arg_arr();
// 	last_commander = commander_addback(&commander, init_commander(data, token->type));
// }

int	is_new_command(int type)
{
	return (type == HERE_DOC || type == RED_INPUT || type == RED_APPEND || RED_OUTPUT);
}

t_commander	*lexical_analysis()
{
	int			is_command;
	char		*data;
	char		**args;
	char		**tmp;
	t_token		*token;
	t_commander	*commander;
	t_commander	*last_commander;

	args = NULL;
	commander = NULL;
	token = ms.token;
	is_command = true;
	while (token)
	{
		if (token->type == STRING)
			data = clean_quote(token->str);
		else
		{
			data = token->str;
			is_command = true;
		}
		if (is_command)
		{
			args = init_arg_arr();
			last_commander = commander_addback(&commander, init_commander(data, token->type));
		}
		tmp = args;
		args = arg_arr_push(args, data);
		free(tmp);
		last_commander->arguments = args;
		is_command = false;
		token = token->next;
	}
	return (commander);
}
