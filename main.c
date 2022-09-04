#include "minishell.h"

t_minishell ms;

t_commander *init_commander(char *command, char **args)
{
	t_commander *commander;

	commander = ft_calloc(sizeof(t_commander), 1);
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
		*commander = new_commander;
	else
	{
		while (i_commander->next)
			i_commander = i_commander->next;
		i_commander->next = new_commander;
		new_commander->prev = i_commander;
	}
}

char	*clean_quote_with_type(char *str, char type, int *pos)
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
		{
			str++;
			(*pos)++;
		}
		(*pos)++;
		new_str = ft_substr(head, 1, str - head - 1);
		tmp = resp;
		resp = ft_strjoin(resp, new_str);
		free(new_str);
		if(*tmp)
			free(tmp);
		head = str;
		str++;
	}
	// printf("STRING: %s LEN: %zu TYPE: %c\n\n", resp, ft_strlen(resp), type);
	return (resp);
}

char	*clean_quote(char *str, int type, int is_command)
{
	int		i;
	char	*data;

	i = 0;
	data = NULL;
	if (type == STRING && !ft_strchr(str, DOLLAR_OP))
	{
		while (str[i])
		{
			if (str[i] == DOUBLE_QUOTE)
				data = clean_quote_with_type(str, DOUBLE_QUOTE, &i);
			else if (str[i] == SINGLE_QUOTE)
				data = clean_quote_with_type(str, SINGLE_QUOTE, &i);
			else if (is_operator(str[i]))
			{
				printf("OPERATOR: %s\n", str[i]);
				data = str;
			}
			else if (!is_whitespace(str[i]))
			{
				data = ft_strtrim(str, " ");
				i += ft_strlen(data);
			}
			i++;
		}
	}
	return(data);
}

char	**arg_arr_push(char **arg_arr, char *str)
{
	int		i;
	int		len;
	char	**new_arr;

	if (!arg_arr)
	{
		arg_arr = ft_calloc(sizeof(char *), 1);
		return (arg_arr);
	}
	len = 0;
	while (arg_arr[len])
	{
		// printf("ARGS: %s\n", arg_arr[len]);
		len++;
	}
	new_arr = ft_calloc(sizeof(char *), len + 1);
	i = 0;
	while (i < len)
	{
		new_arr[i] = arg_arr[i];
		i++;
	}
	new_arr[i] = str;
	// free(arg_arr);
	return (new_arr);
}

void	lexical_analysis()
{
	int			is_command;
	char		*data;
	char		**args;
	t_token		*token;
	t_commander	*commander;

	token = ms.token;
	commander = NULL;
	is_command = true;
	args = NULL;
	while (token)
	{
		if (token->str)
			data = clean_quote(token->str, token->type, is_command);
		if (is_command)
			printf("COMMAND: %s\n", token->str);
		else
		{
			printf("ARGUMENTS: %s\n", data);
			//args = arg_arr_push(args, data);
		}
		is_command = false;
		if (token->type == PIPE)
			is_command = true;
		token = token->next;
	}
// 	while (commander)
// 	{
// 		printf("COMMAND: %s\n", commander->command);
// 		commander = commander->next;
// 	}
// 	while (*args)
// 	{
// 		if (*args)
// 		printf("%s\n", *args);
// 		args++;
// 	}
}

int main(int ac, char **av)
{
	char *input;
	t_token	*token;

	input = "\"echo\" >  \" \" \"   merhaba   \"  birsürüboşluk>>   '$US\"ER' | \"merhaba2\"\"me'\"rh\"'aba45\" >> \"\" merhabaa3 << \"merhaba4\" merhaba";
	// input = "\"deneme\"mes\"aji\" \0";
	// input = "\"echo  \" 'deneme'";
	printf("LEN: %d INPUT: %s\n", ft_strlen(input), input);
	ms.token = tokenize(input);
	token = ms.token;
	while(token)
	{
		printf("String:=>%s-Type: %d Len: %d\n", token->str, token->type, ft_strlen(token->str));
		token = token->next;
	}
	//lexical_analysis();
	// system("leaks a.out");
}
