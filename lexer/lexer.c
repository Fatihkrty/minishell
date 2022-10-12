/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkaratay <fkaratay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 22:08:25 by fkaratay          #+#    #+#             */
/*   Updated: 2022/10/12 23:02:58 by fkaratay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	append_arguments(t_token **tmp_token, t_process *process)
{
	char		*data;
	t_token		*token;

	token = *tmp_token;
	if (token->type == STRING)
	{
		data = clean_quote(token->str);
		process->execute = push_array(process->execute, data);
	}
	else
	{
		data = clean_quote(token->str);
		process->redirects = push_array(process->redirects, data);
		token = token->next;
		*tmp_token = token;
		if (!token || token->type != STRING)
		{
			free_token();
			token_err();
			return (false);
		}
		data = clean_quote(token->str);
		process->redirects = push_array(process->redirects, data);
	}
	return (true);
}

int	lexer(void)
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
		if (!append_arguments(&token, process))
			return (false);
		else
			token = token->next;
	}
	free_token();
	return (true);
}
