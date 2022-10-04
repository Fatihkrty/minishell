#include "../minishell.h"

int	is_parent()
{
	return (ms.parent_pid == getpid());
}