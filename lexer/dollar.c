#include "../minishell.h"

int	valid_op(char c)
{
	return ((c >= 'a' && c <= 'z') ||
			(c >= 'A' && c <= 'Z') ||
			(c >= '0' && c <= '9') ||
			(c == '_') || (c=='?')
	);
}

int	check_dollar(char *str)
{
	int		i;
	char	*pos;
	int		quote_len;

	i = 0;
	quote_len = 0;
	while (str[i] && str[i] != DOLLAR_OP)
	{
		if (str[i] == SINGLE_QUOTE)
			quote_len++;
		i++;
	}
	if (!valid_op(*(ft_strchr(str, DOLLAR_OP) + 1)))
		return (false);
	if (!(quote_len % 2))
		return (true);
	return(false);
}

static char	*get_str(char *str, int	*pos, int type)
{
	int		first;

	first = *pos;
	while (str[*pos] != type)
		(*pos)++;
	return (ft_substr(str, first, *pos - first));
}

char	*parse_dollar_op(char *str)
{
	int		i;
	int		first;
	char	*env;
	char	*result;
	char	*data;

	i = 0;
	result = NULL;
	data = get_str(str, &i, DOLLAR_OP);
	push_new_str(&result, data);
	i++;
	first = i;
	while (valid_op(str[i]))
		(i)++;
	data = ft_substr(str, first, i - first);
	env = get_env(data);
	push_new_str(&result, env);
	free(data);

	data = get_str(str, &i, 0);
	push_new_str(&result, data);
	return (result);
}