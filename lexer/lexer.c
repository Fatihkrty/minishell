#include "../minishell.h"

int	lexer()
{
	t_token		*token;
	t_process	*process;

	token = ms.token;
	while (token)
	{
		if (token->type == PIPE || token->prev == NULL)
		{
			if (token->type == PIPE)
				token = token->next;
			process = init_process();
			process_addback(&ms.process, process);
			ms.process_count++;
		}
		if (!token)
			break ;
		if (token->type == STRING)
			process->execute = push_array(process->execute, clean_quote(token->str));
		else
		{
			process->redirects = push_array(process->redirects, clean_quote(token->str));
			token = token->next;
			if (!token || token->type != STRING)
			{
				free_token();
				token_err();
				return (false);
			}
			if (token)
				process->redirects = push_array(process->redirects, clean_quote(token->str));
		}
		if (token)
			token = token->next;
	}
	free_token();
	return (true);
}
