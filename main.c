#include "minishell.h"
#include "./lexer/lexer.h"

t_minishell ms;

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

int main(int ac, char **av, char **env)
{
	char	*input;
	t_token	*token;

	input = "\"echo\" >  \" \" \"   merhaba   \"  birsürüboşluk>>   '$US\"ER' | \"merhaba2\"\"me'\"rh\"'aba45\" >> \"\" merhabaa3 << \"merhaba4\" merhaba";
	input = "'ls' '-l' '-a' '-h' > file | deneme 123";
	set_env(env);
	printf("%s\n", getenv("USER"));
	// printf("LEN: %zu INPUT: %s\n", ft_strlen(input), input);
	// ms.token = tokenize(input);
	// token = ms.token;
	// while(token)
	// {
	// 	printf("String: %s Type: %d Len: %zu\n", token->str, token->type, ft_strlen(token->str));
	// 	token = token->next;
	// }
	// lexical_analysis();
	// run_commands();

	// system("leaks a.out");
}
