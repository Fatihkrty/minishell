/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scakmak <scakmak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 22:14:21 by fkaratay          #+#    #+#             */
/*   Updated: 2022/10/13 01:03:20 by scakmak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	set_paths(void)
{
	char	*path;

	path = get_env("PATH");
	if (!(*path))
		g_ms.paths = NULL;
	else
	{
		if (g_ms.paths)
			free_array(g_ms.paths);
		g_ms.paths = ft_split(path, ':');
	}
	free(path);
}
