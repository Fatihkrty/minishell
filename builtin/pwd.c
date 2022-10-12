/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkaratay <fkaratay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 13:23:20 by fkaratay          #+#    #+#             */
/*   Updated: 2022/10/12 18:54:46 by fkaratay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	builtin_pwd(char **input)
{
	char	*result;

	result = getcwd((void *)0, 0);
	if (!result)
		perror("minishell ");
	else
		printf("%s\n", result);
	if (!is_parent())
		exit(errno);
}
