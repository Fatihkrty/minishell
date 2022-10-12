/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkaratay <fkaratay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 21:47:57 by fkaratay          #+#    #+#             */
/*   Updated: 2022/10/12 21:50:02 by fkaratay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_token(void)
{
	t_token		*tmp;
	t_token		*token;

	token = ms.token;
	while (token)
	{
		free(token->str);
		token = token->next;
	}
	token = ms.token;
	while (token)
	{
		tmp = token;
		token = token->next;
		free(tmp);
	}
}
