/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scakmak <scakmak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 13:23:12 by fkaratay          #+#    #+#             */
/*   Updated: 2022/10/13 00:28:10 by scakmak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	put_char(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		write(STDOUT_FILENO, &(input[i]), 1);
		i++;
	}
}

void	builtin_echo(char **input)
{
	int	i;
	int	flag;

	i = 1;
	flag = FALSE;
	if (input[i] != NULL)
	{
		flag = ft_strcmp(input[i], "-n");
		if (flag)
			i++;
		while (input[i])
		{
			put_char(input[i]);
			if (input[i + 1])
				write(STDOUT_FILENO, " ", 1);
			i++;
		}
	}
	if (!flag)
		write(STDOUT_FILENO, "\n", 1);
	if (!is_parent())
		exit(EXIT_SUCCESS);
}
