#include "minishell.h"

t_minishell ms;

t_commander *init_commander(char *command, char **args)
{
	t_commander *commander;

	commander = malloc(sizeof(t_commander));
	commander->command = command;
	commander->arguments = args;
	commander->prev = NULL;
	commander->next = NULL;
	return (commander);
}

void	commander_addback(t_commander **commander, t_commander *new_commander)
{
	t_commander *i_commander;

	i_commander = *commander;
	if (!(i_commander))
		*commander = i_commander;
	else
	{
		while(i_commander->next)
			i_commander = i_commander->next;
		
	}
}

char	*clean_quote_with_type(char *str, char type)
{
	char *head;
	char *new_str;
	char *resp;
	char *tmp;

	head = str;
	resp = "";
	str++;
	tmp = NULL;
	while (*str)
	{
		while (*str && *str != type)
			str++;
		new_str = ft_substr(head, 1, str - head - 1);
		tmp = resp;
		resp = ft_strjoin(resp, new_str);
		free(new_str);
		if(*tmp)
			free(tmp);
		head = str;
		str++;
	}
	printf("STRING: %s LEN: %zu\n", resp, ft_strlen(resp));
	return (resp);
}

void	clean_quote(t_commander **commander, char *str, int type, int is_command)
{
	int	i;

	i = 0;
	if (type == STRING && !ft_strchr(str, DOLLAR_OP))
	{
		while (str[i])
		{
			if (str[i] == DOUBLE_QUOTE)
				clean_quote_with_type(str, DOUBLE_QUOTE);
			else if (str[i] == SINGLE_QUOTE)
				clean_quote_with_type(str, SINGLE_QUOTE);
			i++;
		}
	}
	printf("COMMAND: %s\nTYPE: %d\nIS_COMMAND %d\n\n", str, type, is_command);
}

void	lexical_analysis()
{
	t_token		*token;
	t_commander	*commander;
	int			is_command;

	token = ms.token;
	is_command = true;
	commander = NULL;
	while (token)
	{
		clean_quote(&commander, token->str, token->type, is_command);
		is_command = false;
		if (token->type == PIPE)
			is_command = true;
		token = token->next;
	}
}

int main(int ac, char **av)
{
	char *input;
	t_token	*token;

	input = " \"\" \"echo\" > \" \" \"   merhaba   \" '$US\"ER' | \"merhaba2\"\"me'\"rh\"'aba45\" >> \"\" merhabaa3 << \"merhaba4\"\0";
	// input = "\"deneme\"mes\"aji\" \0";
	//input = "den\" << em\"e \0";
	ms.token = tokenize(input);
	// token = ms.token;

	// while(token)
	// {
	// 	printf("String: %s Type: %d\n", token->str, token->type);
	// 	token = token->next;
	// }
	lexical_analysis();
}
