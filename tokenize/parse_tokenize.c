#include "../minishell.h"

int	find_end_pos(char *str, int end_pos, char type)
{
	end_pos++;
	while (str[end_pos])
	{
		end_pos++;
		if(str[end_pos] == type && is_whitespace(str[end_pos]))
			break;
		
	}

	return (end_pos);
}

void	parse_token_string(t_token **token, char *str, int *pos)
{
	int		len;
	int		end_pos;
	char	*token_str;

	end_pos = *pos;

	if (str[end_pos] == '"' && str[end_pos + 1] == '"')
		end_pos += 2;
	else if (str[end_pos] == '\'' && str[end_pos + 1] == '\'')
		end_pos += 2;
	else if (str[end_pos] == '"')
		end_pos = find_end_pos(str, end_pos, '"');
	else if (str[end_pos] == '\'')
		end_pos = find_end_pos(str, end_pos, '\'');
	else
		while (str[end_pos] && !is_whitespace(str[end_pos]))
			end_pos++;
	len = end_pos - *pos;
	token_str = ft_substr(str, *pos, len + 1);
	printf("%d - %s\n", token_str[0], token_str);
	*pos += len;
	if (token_str[0] != 32)
		token_addback(&(*token), init_token(token_str, STRING));
}