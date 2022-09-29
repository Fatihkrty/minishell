#include "../minishell.h"

void	unset(char *str)
{
	int		i;
	int		j;
	char	*data;
	char	**new_env;

	i = 0;
	j = 0;
	data = ft_strjoin(str, "=");
	new_env = ft_calloc(sizeof(char *), get_env_len() + 1);
	while (ms.env[i])
	{
		if (ft_strncmp(ms.env[i], data, ft_strlen(data)))
		{
			new_env[j] = ms.env[i];
			j++;
		}
		i++;
	}
	free(data);
	free(ms.env);
	ms.env = new_env;
}
