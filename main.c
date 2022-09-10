#include "minishell.h"

t_minishell ms;



char	**init_arg_arr()
{
	char	**arg;
	arg = ft_calloc(sizeof(char **), 2);
	return (arg);
}

char	*clean_quote_with_type(char *str, char type, int *pos)
{
	char *head;
	char *new_str;
	char *resp;

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
	data = NULL;
	if (!ft_strchr(str, DOLLAR_OP))
	{
		while (str[i])
		{
			if (str[i] == DOUBLE_QUOTE)
				data = clean_quote_with_type(str, DOUBLE_QUOTE, &i);
			else if (str[i] == SINGLE_QUOTE)
				data = clean_quote_with_type(str, SINGLE_QUOTE, &i);
			else
			{
				data = ft_strtrim(str, " ");
				i += ft_strlen(data);
			}
			i++;
		}
	}
	return(data);
}

void	arg_arr_push(char ***arg_arr, char *str)
{
	// TODO Freelenecek ..
	int		len;
	int		i;
	char	**head;
	char	**new_arr;

	i = 0;
	len = 0;
	head = *arg_arr;
	while (head[len])
		len++;
	new_arr = ft_calloc(sizeof(char **), len + 2);
	while (i < len)
	{
		new_arr[i] = head[i];
		i++;
	}
	new_arr[i] = str;
	*arg_arr = new_arr;
	// return new_arr;
}


int main(int ac, char **av)
{
	char *input;
	t_token	*token;

	input = "\"echo\" >  \" \" \"   merhaba   \"  birsürüboşluk>>   '$US\"ER' | \"merhaba2\"\"me'\"rh\"'aba45\" >> \"\" merhabaa3 << \"merhaba4\" merhaba";
	input = "ls -l -a -h > file1> abc << file2 | deneme 123 456";
	printf("LEN: %d INPUT: %s\n", ft_strlen(input), input);
	ms.token = tokenize(input);
	token = ms.token;
	while(token)
	{
		printf("String: %s Type: %d Len: %d\n", token->str, token->type, ft_strlen(token->str));
		token = token->next;
	}
	lexical_analysis();
	// system("leaks a.out");
}
