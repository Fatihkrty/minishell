#include "../minishell.h"

char *clean_quote_with_type(char *str, char type)
{
	char *head;
	char *new_str;
	char *resp;
	char *tmp;

	resp = ft_calloc(sizeof(char *), 1);
	if (*str == type)
		str++;
	head = str;
	while (*str)
	{
		while (*str && *str != type)
			str++;
		new_str = ft_substr(head, 0, str - head);
		tmp = resp;
		resp = ft_strjoin(resp, new_str);
		free(new_str);
		free(tmp);
		head = str;
		str++;
	}
	return (resp);
}

char *clean_quote(char *str)
{
	int 	i;
	char	*head;

	i = 0;
	head = str;
	if (!ft_strchr(str, DOLLAR_OP))
	{
		while (*str)
		{
			if (*str == DOUBLE_QUOTE)
				return clean_quote_with_type(head, DOUBLE_QUOTE);
			else if (*str == SINGLE_QUOTE)
				return clean_quote_with_type(head, SINGLE_QUOTE);
			str++;
		}
	}
	return (ft_strdup(head));
}
