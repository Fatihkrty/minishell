#include "../minishell.h"

char    *get_path(char *cmd)
{
    char    *path;
    char    **paths;
    char    *new_cmd;
	DIR		*dir;

	dir	= opendir(cmd);
	if (dir && readdir(dir))
	{
		closedir(dir);
		errno = 21;
		perror("minishell");
		exit(errno);
	}
    if (!access(cmd, F_OK))
        return (ft_strdup(cmd));
    paths = ms.paths;
    new_cmd = ft_strjoin("/", cmd);
    while (*paths)
    {
        path = ft_strjoin(*paths, new_cmd);
        if (!access(path, F_OK))
        {
            free(new_cmd);
            return (path);
        }
        free(path);
        paths++;
    }
    free(new_cmd);
	printf("minishell: %s: Command not found\n", new_cmd + 1);
    exit(errno);
}
