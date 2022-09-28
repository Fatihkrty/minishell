#include "../minishell.h"

t_fd_router	*init_router()
{
	t_fd_router	*router;

	router = ft_calloc(sizeof(t_fd_router), 1);
	router->next = NULL;
	router->prev = NULL;
	return (router);
}

void	router_addback(t_fd_router **router, t_fd_router *new_router)
{
	t_fd_router *i_router;

	i_router = *router;
	if (!i_router)
		*router = new_router;
	else
	{
		while(i_router->next)
			i_router = i_router->next;
		i_router->next = new_router;
		new_router->prev = i_router;
	}
}

void	create_pipes()
{
	int	len;
	t_fd_router	*router;

	len = ms.process_count;
	while(len > 0)
	{
		printf("Router Created\n");
		router_addback(&ms.router, init_router());
		len--;
	}
	router = ms.router;
	while (router->next)
	{
		printf("Pipe Created\n");
		pipe(router->fd);
		router = router->next;
	}
}
