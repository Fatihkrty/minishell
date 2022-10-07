#include "../minishell.h"

void	remove_env(char **new_env, char *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (ms.env[i])
	{
		if (ft_strncmp(ms.env[i], data, ft_strlen(data)))
		{
			new_env[j] = ms.env[i];
			j++;
		}
		i++;
	}
	new_env[j] = 0;
}

void	builtin_unset(char **input)
{
	char	*data;
	char	**new_env;

	new_env = ft_calloc(sizeof(char *), get_env_len() + 1);
	input++;
	while (*input)
	{
		data = ft_strjoin(*input, "=");
		remove_env(new_env, data);
		free(data);
		input++;
		if (ms.env != new_env)
			free(ms.env);
		ms.env = new_env;
	}
	set_paths();
}
