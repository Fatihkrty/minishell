#include "../minishell.h"

char    *split_env(char *str)
{
    while(*str != '=')
        str++;
    if (*str)
        str++;
    else
        return (NULL);
    return(str);
}

// TODO
// Freelenmeyecek. Var olan
// heap adresinin pointer
// ilerletilmiş halini döndürüyor.
char    *get_env(char *str)
{
    char    **env;
    char    *new_str;
    size_t  len;

    env = ms.env;
    new_str = ft_strjoin(str, "=");
    len = ft_strlen(new_str);
    while (*env)
    {
        if (!ft_strncmp(*env, new_str, len))
        {
            free(new_str);
            return(split_env(*env));
        }
        env++;
    }
    free(new_str);
    return (NULL);
}