/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkaratay <fkaratay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 22:14:21 by fkaratay          #+#    #+#             */
/*   Updated: 2022/10/12 22:14:22 by fkaratay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	set_paths(void)
{
	char	*path;

	path = get_env("PATH");
	if (!(*path))
		ms.paths = NULL;
	else
	{
		if (ms.paths)
			free_array(ms.paths);
		ms.paths = ft_split(path, ':');
	}
	free(path);
}
