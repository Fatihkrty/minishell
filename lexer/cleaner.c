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

char *clean_quote_with_type(char *str, int *pos, char type)
{
	int		first;
	char	*new_str;

	(*pos)++;
	first = *pos;
	while (str[*pos] && str[*pos] != type)
		(*pos)++;
	new_str = ft_substr(str, first, *pos - first);
	if (str[*pos])
		(*pos)++;
	return (new_str);
}

// char	*parse_dollar_op(char *str)
// {
// 	char	*tmp;
// 	char	*head;
// 	char	*new_str;
// 	head = str;
// 	new_str = NULL;
// 	while (*str)
// 	{
// 		while (*str && *str != '$')
// 			str++;
// 		if (str - head > 0)
// 		{
// 			tmp = ft_substr(head, 0, str - head);
// 			push_new_str(&new_str, tmp);
// 			free(tmp);
// 			head = str;
// 		}
// 		if (*str == '$')
// 		{
// 			str++;
// 			head = str;
// 			while(*str && valid_op(*str))
// 				str++;
// 			tmp = ft_substr(head, 0, str - head);
// 			push_new_str(&new_str, get_env(tmp));
// 			free(tmp);
// 			head = str;
// 		}
// 	}
// 	tmp = new_str;
// 	new_str = clean_quote_with_type(new_str, DOUBLE_QUOTE);
// 	free(tmp);
// 	return (new_str);
// }

char *clean_quote(char *str)
{
	int		i;
	int		first;
	char	*data;
	char	*result;

	i = 0;
	result = NULL;
	while (str[i])
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
