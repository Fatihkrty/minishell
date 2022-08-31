#include "minishell.h"

t_minishell ms;


void	parse_dollar()
{
	t_token	*token;
	char	*str;

	token = ms.token;
	while(token)
	{
		printf("String: %s Type: %u\n", token->str, token->type);
		token = token->next;
	}
}


int	main(int ac, char **av, char **env)
{
	char	*input;
	t_token	*token;

	input = "\"\" \"   echo\" > \" \" \"   merhaba   \" '$US\"ER' | \"merh aba2\"me'\"rh\"'aba45 >> \"\" merhaba3 << merhaba4 < merhaba5 \"merhaba6\" ";
	// input = "'den\" em\"e'";
	ms.token = tokenize(input);
	ms.env = env;
	parse_dollar();
	// while(*env)
	// {
	// 	printf("%s\n", *env);
	// 	env++;
	// }
	// token = ms.token;
	// while (token)
	// {
	// 	printf("String: %s Type: %u\n", token->str, token->type);
	// 	token = token->next;
	// }

}
