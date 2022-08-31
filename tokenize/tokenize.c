#include "../minishell.h"

t_token	*init_token(char *str, enum e_ttype type)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	token->type = type;
	token->str = str;
	token->prev = NULL;
	token->next = NULL;
	return (token);
}

void	token_addback(t_token **token, t_token *new_token)
{
	t_token *i_token;

	i_token = *token;
	if (!(i_token))
		*token = new_token;
	else
	{
		while (i_token->next)
			i_token = i_token->next;
		i_token->next = new_token;
		new_token->prev = i_token;
	}
}

t_token	*tokenize(char *str)
{
	int		pos;
	t_token	*token;

	pos = 0;
	token = NULL;
	while (str[pos])
	{
		if (str[pos] == '>' && str[pos + 1] == '>')
		{
			token_addback(&token, init_token(NULL, RED_APPEND));
			pos++;
		}
		else if (str[pos] == '<' && str[pos + 1] == '<')
		{
			token_addback(&token, init_token(NULL, HERE_DOC));
			pos++;
		}
		else if (str[pos] == '|')
			token_addback(&token, init_token(NULL, PIPE));
		else if (str[pos] == '<')
			token_addback(&token, init_token(NULL, RED_INPUT));
		else if (str[pos] == '>')
			token_addback(&token, init_token(NULL, RED_OUTPUT));
		else
			parse_token_string(&token, str, &pos);
		pos++;
	}
	return (token);
}