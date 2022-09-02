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

void	parse_token_string(t_token **token, char *str, int *pos)
{
	int		len;
	int		end_pos;
	char	*token_str;

	end_pos = *pos;
	//printf("%s - %d - %d\n", str + *pos, ft_strlen(str), *pos);
	if (str[end_pos] == DOUBLE_QUOTE && str[end_pos + 1] == DOUBLE_QUOTE)
		end_pos++;
	else if (str[end_pos] == SINGLE_QUOTE && str[end_pos + 1] == SINGLE_QUOTE)
		end_pos++;
	else if (str[end_pos] == DOUBLE_QUOTE)
		end_pos = find_end_pos(str, end_pos, DOUBLE_QUOTE);
	else if (str[end_pos] == SINGLE_QUOTE)
		end_pos = find_end_pos(str, end_pos, SINGLE_QUOTE);
	else
		while (str[end_pos] && !is_whitespace(str[end_pos]))
			end_pos++;
	len = end_pos - *pos;
	token_str = ft_substr(str, *pos, len + 1);
	//printf("%d - %zu - %s - %d\n", token_str[0], ft_strlen(token_str), token_str, len + 1);
	*pos += len;
	if (ft_strlen(token_str) != 1 && token_str[0] != 32)
		token_addback(&(*token), init_token(token_str, STRING));
}