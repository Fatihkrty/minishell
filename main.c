#include "minishell.h"

t_minishell ms;


t_commander *init_commander(char *command)
{
	t_commander *commander;

	commander = ft_calloc(sizeof(t_commander), 1);
	commander->command = command;
	commander->arguments = NULL;
	commander->prev = NULL;
	commander->next = NULL;
	return (commander);
}

t_commander	*commander_addback(t_commander **commander, t_commander *new_commander)
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
	return (new_commander);
}

char	**init_arg_arr()
{
	char	**arg;
	arg = ft_calloc(sizeof(char **), 2);
	return (arg);
}

char	*clean_quote_with_type(char *str, char type, int *pos)
{
	char	*head;
	char	*new_str;
	char	*resp;

	head = str;
	resp = "";
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
		resp = ft_strjoin(resp, new_str);
		head = str;
		str++;
	}
	return (resp);
}

char	*clean_quote(char *str)
{
	int		i;
	char	*data;

	i = 0;
	data = str;
	if (!ft_strchr(str, DOLLAR_OP))
	{
		while (str[i])
		{
			if (str[i] == DOUBLE_QUOTE)
				data = clean_quote_with_type(str, DOUBLE_QUOTE, &i);
			else if (str[i] == SINGLE_QUOTE)
				data = clean_quote_with_type(str, SINGLE_QUOTE, &i);
			else
				data = str;
			i++;
		}
	}
	return(data);
}

void	arg_arr_push(char ***arg_arr, char *str)
{
	int		len;
	int		i;
	char	**head;
	char	**new_arr;

	i = 0;
	len = 0;
	head = *arg_arr;
	while (head && head[len])
		len++;
	new_arr = ft_calloc(sizeof(char **), len + 2);
	while (i < len)
	{
		new_arr[i] = head[i];
		i++;
	}
	new_arr[i] = str;
	*arg_arr = new_arr;
}

void	fill_commander(char *str)
{
	t_commander	*commander;
	t_commander	*last_commander;


}

void	lexical_analysis()
{
	int			is_command;
	char		*data;
	char		**args;
	t_token		*token;
	t_commander	*commander;
	t_commander	*last_commander;

	token = ms.token;
	is_command = true;
	args = NULL;
	commander = NULL;
	while (token)
	{
		if (token->type == STRING)
			data = clean_quote(token->str);
		else
			data = token->str;
		if (is_command)
		{
			args = init_arg_arr();
			if (is_operator(data))
				data = NULL;
			last_commander = commander_addback(&commander, init_commander(data));
		}
		arg_arr_push(&args, data);
		last_commander->arguments = args;
		is_command = false;
		if (token->type == PIPE)
			is_command = true;
		token = token->next;
	}
	ms.commander = commander;
	// while (commander)
	// {
	// 	int c = 0;
	// 	printf("COMMANDER COMMAND: %s\n", commander->command);
	// 	while (commander->arguments[c])
	// 	{
	// 		printf("COMMANDER ARGMENTS: %s\n", commander->arguments[c]);
	// 		c++;
	// 	}
	// 	commander = commander->next;
	// }
}

void	run_commands()
{
	t_commander	*commander;

	commander = ms.commander;
	while (commander)
	{
		printf("RESULT: %d\n", execve("/bin/ls", commander->arguments, NULL));
		commander = commander->next;
	}
}

int main(int ac, char **av)
{
	char *input;
	t_token	*token;

	//input = "\"echo\" >  \" \" \"   merhaba   \"  birsürüboşluk>>   '$US\"ER' | \"merhaba2\"\"me'\"rh\"'aba45\" >> \"\" merhabaa3 << \"merhaba4\" merhaba";
	//input = "ls -l -a -h >              file123>>deneme << file2 | deneme 123 456";
	//input = "echo \"den\"\"eme\" 'fatih'";
	input = "\"ls\" '-l' -a -h"; // echo deneme "123 4567
	printf("LEN: %zu INPUT: %s\n", ft_strlen(input), input);
	ms.token = tokenize(input);
	token = ms.token;
	while(token)
	{
		printf("String: %s Type: %d Len: %zu\n", token->str, token->type, ft_strlen(token->str));
		token = token->next;
	}
	lexical_analysis();
	run_commands();

	// system("leaks a.out");
}
