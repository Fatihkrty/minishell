#include "../minishell.h"

char    *get_path(char *cmd)
{
    char    *path;
    char    **paths;
    char    *new_cmd;

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
    return (NULL);
}
