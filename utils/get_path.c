#include "../minishell.h"

void    check_dir(char *cmd)
{
    DIR		*dir;

    if (!cmd)
        exit(EXIT_SUCCESS);
	dir	= opendir(cmd);
	if (dir && readdir(dir))
	{
		closedir(dir);
        directory_err();
	}
}

char    *get_path(char *cmd)
{
    char    *path;
    char    **paths;
    char    *new_cmd;

    check_dir(cmd);
    if (!access(cmd, F_OK))
        return (ft_strdup(cmd));
    paths = ms.paths;
    if (!paths)
        command_err();
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
	return (NULL);
}
