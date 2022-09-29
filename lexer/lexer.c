#include "../minishell.h"

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
	*token = i_token->next;
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
		{
			printf("ARG: %s\n", token->str);
			args = append_arguments(args, token->str);
		}
		else
			redirects = append_redirects(&token, redirects);
		process->execute = args;
		process->redirects = redirects;
		if (token)
			token = token->next;
	}
	return (process);
}
