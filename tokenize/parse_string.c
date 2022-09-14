#include "../minishell.h"

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
	while (str[end_pos])
	{
		if (is_whitespace(str[end_pos]))
			break;
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