#include "../minishell.h"

t_token	*init_token(char *str, enum e_ttype type)
{
	t_token	*token;

	token = ft_calloc(sizeof(t_token), 1);
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
	if (!i_token)
		*token = new_token;
	else
	{
		while (i_token->next)
			i_token = i_token->next;
		i_token->next = new_token;
		new_token->prev = i_token;
	}
}

void	tokenize(char *str)
{
	while (*str)
	{
		if (is_operator(str) == RED_APPEND)
		{
			token_addback(&ms.token, init_token(ft_strdup(">>"), RED_APPEND));
			str+=2;
		}
		else if (is_operator(str) == HERE_DOC)
		{
			token_addback(&ms.token, init_token(ft_strdup("<<"), HERE_DOC));
			str+=2;
		}
		else if (is_operator(str) == PIPE)
		{
			token_addback(&ms.token, init_token(ft_strdup("|"), PIPE));
			str++;
		}
		else if (is_operator(str) == RED_INPUT)
		{
			token_addback(&ms.token, init_token(ft_strdup("<"), RED_INPUT));
			str++;
		}
		else if (is_operator(str) == RED_OUTPUT)
		{
			token_addback(&ms.token, init_token(ft_strdup(">"), RED_OUTPUT));
			str++;
		}
		else
			parse_token_string(&str);
	}
}
