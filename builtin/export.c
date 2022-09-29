#include "../minishell.h"

int	get_env_len()
{
	char	**env;

	env = ms.env;
	while(*env)
		env++;
	return(env - ms.env);
}

int	check_env(char *str)
{
	char	*head;

	head = ft_strchr(str, '=');
	if (!head)
		return (false);
	if (head == str)
		return (false);
	return (true);
}

void	export(char *str)
{
	int		len;
	int		i;
	char	**env;
	char	**new_env;

	if (!check_env(str))
		return ;
	i = 0;
	env = ms.env;
	len = get_env_len();
	new_env = ft_calloc(sizeof(char *), len + 2);
	while (env[i])
	{
		new_env[i] = env[i];
		i++;
	}
	new_env[i] = str;
	free(ms.env);
	ms.env = new_env;
}