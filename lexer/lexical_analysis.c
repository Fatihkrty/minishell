#include "../minishell.h"


t_process *lexical_analysis()
{
	char		**tmp;
	char		**redirects;
	char		**args;
	t_token		*token;
	t_process	*process;

	token = ms.token;
	while (token)
	{
		if (token->type == PIPE || token->prev == NULL)
		{
			if (token->type == PIPE)
				token = token->next;
			args = init_args();
			redirects = init_args();
			process = init_process();
			process_addback(&ms.process, process);
			ms.process_count++;
		}
		if (token->type == STRING)
		{
			tmp = args;
			args = push_args(args, clean_quote(token->str));
			free(tmp);
		}
		else
		{
			tmp = redirects;
			redirects = push_args(redirects, token->str);
			free(tmp);
			token = token->next;
			if (token)
			{
				tmp = redirects;
				redirects = push_args(redirects, token->str);
				free(tmp);
			}
		}
		process->execute = args;
		process->redirects = redirects;
		if (token)
			token = token->next;
	}
	return (process);
}
