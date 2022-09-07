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

int	find_end_pos(char *str, int end_pos, char type)
{
	end_pos++;
	while (str[end_pos])
	{
		if(str[end_pos] == type && is_whitespace(str[end_pos + 1]))
			break;
		end_pos++;
	}
	return (end_pos);
}

int	without_quote_parse(char *str, int end_pos)
{
	while (str[end_pos] && !is_whitespace(str[end_pos]))
	{
		// printf("ACACBACB: %d\n", end_pos);
		end_pos++;
	}
	return (end_pos);
}

void	parse_token_string(t_token **token, char *str, int *pos)
{
	int		len;
	int		end_pos;
	char	*token_str;

	end_pos = *pos;
	if (str[end_pos] == DOUBLE_QUOTE && str[end_pos + 1] == DOUBLE_QUOTE)
		end_pos++;
	else if (str[end_pos] == SINGLE_QUOTE && str[end_pos + 1] == SINGLE_QUOTE)
		end_pos++;
	else if (str[end_pos] == DOUBLE_QUOTE)
		end_pos = find_end_pos(str, end_pos, DOUBLE_QUOTE);
	else if (str[end_pos] == SINGLE_QUOTE)
		end_pos = find_end_pos(str, end_pos, SINGLE_QUOTE);
	else
		end_pos = without_quote_parse(str, end_pos);
	len = end_pos - *pos + 1;
	token_str = ft_substr(str, *pos, len);
	*pos = end_pos;
	if (ft_strlen(token_str) != 1 && token_str[0] != 32)
		token_addback(&(*token), init_token(token_str, STRING));
}

t_token	*tokenize(char *str)
{
	int		pos;
	t_token	*token;

	pos = 0;
	token = NULL;
	int	len = ft_strlen(str);
	while (str[pos] && pos < len)
	{
		if (str[pos] == '>' && str[pos + 1] == '>')
		{
			token_addback(&token, init_token(">>", RED_APPEND));
			pos++;
		}
		else if (str[pos] == '<' && str[pos + 1] == '<')
		{
			token_addback(&token, init_token("<<", HERE_DOC));
			pos++;
		}
		else if (str[pos] == '|')
			token_addback(&token, init_token("|", PIPE));
		else if (str[pos] == '<')
			token_addback(&token, init_token("<", RED_INPUT));
		else if (str[pos] == '>')
			token_addback(&token, init_token(">", RED_OUTPUT));
		else
			parse_token_string(&token, str, &pos);
		pos++;
	}
	return (token);
}