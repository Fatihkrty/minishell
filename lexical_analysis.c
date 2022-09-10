#include "minishell.h"


void	lexical_analysis()
{
	int			is_command;
	char		*data;
	char		**args;
	t_token		*token;
	t_commander	*commander;

	token = ms.token;
	is_command = true;
	args = init_arg_arr();
	commander = NULL;
	while (token)
	{
		// int len = 0;
		// while (*args && args[len])
		// 	len++;
		// printf("LEN: %d\n", len);
		if (token->type == STRING)
			data = clean_quote(token->str);
		else
			data = token->str;
		if (is_command)
		{
			// commander = init_commander(data, NULL);
			// (args)[0] = "DENEME MESAJI COMMAND";

			// printf("COMMAND: %s - %p\n", data, args);
			args = init_arg_arr();
			commander_addback(&commander, init_commander(data, NULL));
		}
		else
		{
			arg_arr_push(&args, data);
			// (args)[0] = "DENEME MESAJI ARGUMENTS";
			// printf("ARGS: %s - %p\n", data, args);
		}
		commander->arguments = args;
		is_command = false;
		if (token->type == PIPE)
			is_command = true;
		token = token->next;
	}
	while (commander)
	{
		int c = 0;
		printf("COMMANDER COMMAND: %s\n", commander->command);
		while (commander->arguments[c])
		{
			printf("COMMANDER ARGMENTS: %s\n", commander->arguments[c]);
			c++;
		}
		commander = commander->next;
	}
	

}