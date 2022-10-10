#include "../minishell.h"

int	valid_op(char c)
{
	return ((c >= 'a' && c <= 'z') ||
			(c >= 'A' && c <= 'Z') ||
			(c >= '0' && c <= '9') ||
			(c == '_') || (c=='?')
	);
}

void	push_new_str(char **new_str, char *str)
{
	char	*tmp;

	if (!(*new_str))
	{
		*new_str = ft_strdup(str);
		return ;
	}
	tmp = *new_str;
	*new_str = ft_strjoin(*new_str, str);
	free(tmp);
}
char	*parse_dollar_op(char *str, int *pos)
{
	int		first;
	char	*env;
	char	*result;

	while (str[*pos] != DOLLAR_OP)
		(*pos)++;
	(*pos)++;
	first = *pos;
	while (valid_op(str[*pos]))
		(*pos)++;
	env = ft_substr(str, first, *pos - first);
	result = get_env(env);
	free(env);
	return (result);
}

char *clean_quote_with_type(char *str, int *pos, char type)
{
	int		first;
	char	*new_str;

	if (type == DOUBLE_QUOTE && ft_strchr(str, DOLLAR_OP))
	{
		
	}
	(*pos)++;
	first = *pos;
	while (str[*pos] && str[*pos] != type)
		(*pos)++;
	new_str = ft_substr(str, first, *pos - first);
	if (str[*pos])
		(*pos)++;
	return (new_str);
}


char *clean_quote(char *str)
{
	int		i;
	int		first;
	char	*data;
	char	*result;

	i = 0;
	result = NULL;
	while (str[i]) // $USER'ABC123'
	{
		if (str[i] == DOUBLE_QUOTE)
		{
			data = clean_quote_with_type(str, &i, DOUBLE_QUOTE);
			push_new_str(&result, data);
		}
		else if (str[i] == SINGLE_QUOTE)
		{
			data = clean_quote_with_type(str, &i, SINGLE_QUOTE);
			push_new_str(&result, data);
		}
		else
		{
			first = i;
			while (str[i] && str[i] != DOUBLE_QUOTE && str[i] != SINGLE_QUOTE)
				i++;
			data = ft_substr(str, first, i - first);
			push_new_str(&result, data);
		}
		free(data);
	}
	return (result);
}
