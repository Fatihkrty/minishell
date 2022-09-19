#include "../minishell.h"

char	*clean_quote_with_type(char *str, char type, int *pos)
{
	char	*head;
	char	*new_str;
	char	*resp;
	char	*tmp;

	head = str;
	resp = ft_calloc(sizeof(char *), 1);
	tmp = resp;
	str++;
	while (*str)
	{
		while (*str && *str != type)
		{
			str++;
			(*pos)++;
		}
		(*pos)++;
		new_str = ft_substr(head, 1, str - head - 1);
		tmp = resp;
		resp = ft_strjoin(resp, new_str);
		head = str;
		free(new_str);
		free(tmp);
		str++;
	}
	return (resp);
}

char	*clean_quote(char *str)
{
	int	i;

	i = 0;
	if (!ft_strchr(str, DOLLAR_OP))
	{
		while (str[i])
		{
			if (str[i] == DOUBLE_QUOTE)
				str = clean_quote_with_type(str, DOUBLE_QUOTE, &i);
			else if (str[i] == SINGLE_QUOTE)
				str = clean_quote_with_type(str, SINGLE_QUOTE, &i);
			else
				str = str;
			i++;
		}
	}
	return(str);
}
