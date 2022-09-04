#include "../minishell.h"

int		is_operator(char *str)
{
	return (
		(str[0] == '<' && str[1] == '<') ||
		(str[0] == '>' && str[1] == '>') ||
		str[0] == '<' ||
		str[0] == '>' ||
		str[0] == '|'
	);
}
