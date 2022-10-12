/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkaratay <fkaratay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 13:23:18 by fkaratay          #+#    #+#             */
/*   Updated: 2022/10/12 18:54:01 by fkaratay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	env_len(void)
{
	char	**env;

	env = ms.env;
	while (*env)
		env++;
	return (env - ms.env);
}

int	check_env(char *str)
{
	char	*head;

	head = ft_strchr(str, '=');
	if (!head)
		return (false);
	if (head == str)
		return (false);
	while (*str)
	{
		if (is_whitespace(*str))
			return (false);
		str++;
	}
	return (true);
}

void	add_env(char *str)
{
	int		i;
	char	**env;
	char	**new_env;

	i = 0;
	env = ms.env;
	new_env = ft_calloc(sizeof(char **), env_len() + 2);
	while (env[i])
	{
		new_env[i] = ft_strdup(env[i]);
		i++;
	}
	new_env[i] = ft_strdup(str);
	free_array(ms.env);
	ms.env = new_env;
}

int	is_include(char *str)
{
	int		i;
	int		j;
	char	**env;

	i = 0;
	env = ms.env;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && str[j])
		{
			if (str[j] == '=' && env[i][j] == '=')
				return (i);
			if (str[j] != env[i][j])
				break ;
			j++;
		}
		i++;
	}
	return (0);
}

void	builtin_export(char **input)
{
	int		pos;
	char	*tmp;

	input++;
	while (*input)
	{
		if (check_env(*input))
		{
			pos = is_include(*input);
			if (pos)
			{
				tmp = ms.env[pos];
				ms.env[pos] = ft_strdup(*input);
				free(tmp);
			}
			else
				add_env(*input);
		}
		input++;
	}
}
