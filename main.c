#include "minishell.h"

int	is_whitespace(char c)
{
	// TODO doldurulacak..
	return (c  == ' ');
}

t_token	*init_token(char *str, enum e_ttype type)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	token->type = type;
	token->str = str;
	token->prev = NULL;
	token->next = NULL;
	return (token);
}

void	token_addback(t_token **token, t_token *new_token)
{
	t_token *i_token;

	i_token = *token;
	if (!(i_token))
		*token = new_token;
	else
	{
		while (i_token->next)
			i_token = i_token->next;
		i_token->next = new_token;
		new_token->prev = i_token;
	}
}

void	parse_token_string(t_token **token, char *str, int *pos)
{
	int		len;
	int		end_pos;
	char	*token_str;

	end_pos = *pos;

	if (str[end_pos] == '"' && str[end_pos + 1] == '"')
		end_pos += 2;
	else if (str[end_pos] == '"' && is_whitespace(str[end_pos + 1]))
	{
		end_pos++;
		while (str[end_pos] && str[end_pos] != '"')
			end_pos++;
		end_pos++;
	}
	else if (str[end_pos] == '\'' && str[end_pos + 1] == '\'')
		end_pos += 2;
	else if (str[end_pos] == '\'' && is_whitespace(str[end_pos + 1]))
	{
		end_pos++;
		while (str[end_pos] && str[end_pos] != '\'')
			end_pos++;
		end_pos++;
	}
	else
	{
		while (str[end_pos] && !is_whitespace(str[end_pos]))
			end_pos++;
	}
	len = end_pos - *pos;
	token_str = ft_substr(str, *pos, len);
	*pos += len;
	if (token_str[0])
		token_addback(&(*token), init_token(token_str, EMPTY));
}

t_token	*tokenize(char *str)
{
	int		pos;
	t_token	*token;

	pos = 0;
	token = NULL;
	while (str[pos])
	{
		if (str[pos] == '>' && str[pos + 1] == '>')
			token_addback(&token, init_token(NULL, RED_APPEND));
		else if (str[pos] == '<' && str[pos + 1] == '<')
			token_addback(&token, init_token(NULL, HERE_DOC));
		else if (str[pos] == '|')
			token_addback(&token, init_token(NULL, PIPE));
		else if (str[pos] == '<')
			token_addback(&token, init_token(NULL, RED_INPUT));
		else if (str[pos] == '>')
			token_addback(&token, init_token(NULL, RED_OUTPUT));
		else
			parse_token_string(&token, str, &pos);
		pos++;
	}
	return (token);
}

int	main(void)
{
	char	*input;
	t_token	*token; 
	input = "\"\" \"          echo\" > \" \" \"   merhaba   \" '$US\"ER' | \"merhaba2\"merhaba45 >> \"\" merhaba3 << merhaba4 < merhaba5 \"merhaba6\" ";
	token = tokenize(input);

	while (token)
	{
		printf("String: %s Type: %u\n", token->str, token->type);
		token = token->next;
	}

}


// void	set_command(char *head)
// {
// 	size_t	len;
// 	size_t	i;

// 	// Tırnağa kadar olan stringin uzunluğunu
// 	// ram adresinden çıkartarak alıyor.
// 	// malloc için +2 eklendi. Biri " için
// 	// diğeri ise NULL değeri için
// 	len = ms.input_str - head + 1;
// 	ms.command = malloc(sizeof(char) * len + 1);
// 	i = 0;
// 	while(i < len)
// 	{
// 		ms.command[i] = head[i];
// 		i++;
// 	}

// 	printf("%s\n", ms.command);
// 	ms.command[i] = '\0';
// }

// void	quote_parse_with_type(char type)
// {
// 	char	*head;

// 	head = ms.input_str++; // input_strnin başlangıç noktası str ye atandı ve typeden kurtulmak için bir adım ileri gidildi.
// 	while (*ms.input_str && *ms.input_str != type)
// 		ms.input_str++;
// 	set_command(head);
// }

// void	parse_quote()
// {
// 	skip_space(); // En baştaki boşluk karakterleri atlanıyor.
// 	while (*ms.input_str)
// 	{
// 		if (*ms.input_str == '"')
// 			quote_parse_with_type('"');
// 		ms.input_str++;
// 	}
// }