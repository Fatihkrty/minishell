/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkaratay <fkaratay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 13:23:09 by fkaratay          #+#    #+#             */
/*   Updated: 2022/10/12 13:23:10 by fkaratay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	builtin_cd(char **input)
{
	char	*home;
    char    *err;
	
	if (input[1] != NULL)
    {
		if (chdir(input[1]) != 0)
            perror("minishell ");
    }
	else
	{
		home = getenv("HOME");
		if (home && *home)
			if (chdir(home))
				perror("minishell ");
	}
    if (!is_parent())
	    exit (errno);
}
