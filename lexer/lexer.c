#include "../minishell.h"


void	append_redirects(t_process *process, t_token **token)
{
	t_token	*i_token;

	i_token = *token;
	process->redirects = push_array(process->redirects, i_token->str);
	i_token = i_token->next;
	*token = i_token;
	if (i_token)
		process->redirects = push_array(process->redirects, clean_quote(i_token->str));
}

void	lexer()
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
		if (token->type == STRING)
			process->execute = push_array(process->execute, clean_quote(token->str));
		else
		{
			process->redirects = push_array(process->redirects, ft_strdup(token->str));
			token = token->next;
			if (token)
				process->redirects = push_array(process->redirects, clean_quote(token->str));
		}
		if (token)
			token = token->next;
	}
	free_token();
}
