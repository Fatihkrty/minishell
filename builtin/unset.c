#include "../minishell.h"

void	remove_env(char *data)
{
	int		i;
	int		j;
	char	**new_env;

	i = 0;
	j = 0;
	new_env = ft_calloc(sizeof(char *), env_len() + 1);
	while (ms.env[i])
	{
		if (ft_strncmp(ms.env[i], data, ft_strlen(data)))
		{
			new_env[j] = ft_strdup(ms.env[i]);
			j++;
		}
		i++;
	}
	new_env[j] = 0;
	free_array(ms.env);
	ms.env = new_env;
}

void	builtin_unset(char **input)
{
	char	*data;

	input++;
	while (*input)
	{
		data = ft_strjoin(*input, "=");
		remove_env(data);
		free(data);
		input++;
	}
	set_paths();
}
