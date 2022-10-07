#include "../minishell.h"
#include <ctype.h>

int	ft_get_arg_count(char **input)
{
	int	i;

	i = 0;
	while (input[i])
		i++;
	return (i);
}

int ft_isnumber_with_sign(char *arg)
{
	while (*arg)
	{
		if ((*arg >= '0' && *arg <= '9') || *arg == '+' || *arg == '-')
			arg++;
		else
			return (false);
	}
	return (true);
}


void	builtin_exit(char **input)
{
	if (ft_get_arg_count(input) == 1)
	{
		printf("exit\n");
		exit(55); // Last command exit status variable
	}
	else
	{
		if (ft_isnumber_with_sign(input[1]))
		{
			if (ft_get_arg_count(input) > 2)
			{
                write(2, "exit\nminishell: exit: too many arguments\n", 41);
				//global.exitstatus=1
				return ;
			}
			exit(ft_atoi(input[1]) % 256);
		}
        write(2, "exit\nminishell: exit: numeric argument required\n", 48);
		exit(-1 % 255);
	}
}