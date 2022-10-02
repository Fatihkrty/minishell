#include "../minishell.h"

t_process *init_process()
{
	t_process *process;

	process = ft_calloc(sizeof(t_process), 1);
	pipe(process->fd);
	process->execute = NULL;
	process->prev = NULL;
	process->next = NULL;
	return (process);
}

void	process_addback(t_process **process, t_process *new_process)
{
	t_process *i_process;

	i_process = *process;
	if (!(i_process))
		*process = new_process;
	else
	{
		while (i_process->next)
			i_process = i_process->next;
		i_process->next = new_process;
		new_process->prev = i_process;
	}
}

char	**append_arguments(char **args, char *str)
{
	char	**tmp;
	char	**new_args;

	tmp = args;
	new_args = push_array(args, clean_quote(str));
	free(tmp);
	return (new_args);
}

char	**append_redirects(t_token **token, char **redirects)
{
	char	**tmp;
	t_token	*i_token;

	i_token = *token;
	tmp = redirects;
	redirects = push_array(redirects, i_token->str);
	free(tmp);
	i_token = i_token->next;
	*token = i_token;
	if (i_token)
	{
		tmp = redirects;
		redirects = push_array(redirects, clean_quote(i_token->str));
		free(tmp);
	}
	return (redirects);
}


t_process *lexer()
{
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
			args = init_array();
			redirects = init_array();
			process = init_process();
			process_addback(&ms.process, process);
			ms.process_count++;
		}
		if (token->type == STRING)
			args = append_arguments(args, token->str);
		else
			redirects = append_redirects(&token, redirects);
		process->execute = args;
		process->redirects = redirects;
		if (token)
			token = token->next;
	}
	return (process);
}