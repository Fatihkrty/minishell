#include "../minishell.h"

int	valid_op(char c)
{
	return ((c >= 'a' && c <= 'z') ||
			(c >= 'A' && c <= 'Z') ||
			(c >= '0' && c <= '9') ||
			(c == '_')
	);
}

void	push_new_str(char **new_str, char *str)
{
	char	*tmp;

	if (!str)
		return ;
	if (!(*new_str))
	{
		*new_str = ft_strdup(str);
		return ;
	}
	tmp = *new_str;
	*new_str = ft_strjoin(*new_str, str);
	free(tmp);
}

char *clean_quote_with_type(char *str, char type)
{
	char	*tmp;
	char	*head;
	char	*new_str;

	head = str;
	new_str = NULL;
	while (*str)
	{
		if (*str == type)
			str++;
		head = str;
		while (*str && *str != type)
			str++;
		tmp = ft_substr(head, 0, str - head);
		push_new_str(&new_str, tmp);
		free(tmp);
		str++;
	}
	return (new_str);
}

char	*parse_dollar_op(char *str)
{
	char	*tmp;
	char	*head;
	char	*new_str;

	head = str;
	new_str = NULL;
	while (*str)
	{
		while (*str && *str != '$')
			str++;
		if (str - head > 0)
		{
			tmp = ft_substr(head, 0, str - head);
			push_new_str(&new_str, tmp);
			free(tmp);
			head = str;
		}
		if (*str == '$')
		{
			str++;
			head = str;
			while(*str && valid_op(*str))
				str++;
			tmp = ft_substr(head, 0, str - head);
			push_new_str(&new_str, getenv(tmp));
			free(tmp);
			head = str;
		}
	}
	tmp = new_str;
	new_str = clean_quote_with_type(new_str, DOUBLE_QUOTE);
	free(tmp);
	return (new_str);
}

char *clean_quote(char *str)
{
	char	*head;
	char	*dollar_str;

	head = str;
	while (*str)
	{
		if (ft_strchr(str, DOLLAR_OP))
			return parse_dollar_op(str);
		if (*str == DOUBLE_QUOTE)
			return clean_quote_with_type(head, DOUBLE_QUOTE);
		else if (*str == SINGLE_QUOTE)
			return clean_quote_with_type(head, SINGLE_QUOTE);
		str++;
	}
	return (ft_strdup(head));
}
