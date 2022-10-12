/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkaratay <fkaratay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 22:14:18 by fkaratay          #+#    #+#             */
/*   Updated: 2022/10/12 22:14:19 by fkaratay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	set_env(char **env)
{
	size_t	i;
	size_t	len;
	char	**head;

	head = env;
	while (*head)
		head++;
	len = head - env;
	ms.env = ft_calloc(sizeof(char **), len + 1);
	i = -1;
	while (++i < len)
		ms.env[i] = ft_strdup(env[i]);
}
