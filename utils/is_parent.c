#include "../minishell.h"

int	is_parent(void)
{
	return (ms.parent_pid == getpid());
}
