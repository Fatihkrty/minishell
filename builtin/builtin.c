#include "../minishell.h"

int	is_builtin(char *command)
{
	if (ft_strcmp(command, "cd")) // ilkse mainde değilse child processde. Yönlendirme yok
        return (CD);
	if (ft_strcmp(command, "env")) // farketmez. child olabilir.
        return (ENV);
	if (ft_strcmp(command, "pwd")) // child processde. Konumu main processden miras alıyor. Yönlendirme output var
        return (PWD);
	if (ft_strcmp(command, "echo")) // Sürekli child olabilir
        return (ECHO);
	if (ft_strcmp(command, "exit")) // ilkse mainde değilse child processde. yönlendirme yok
        return (EXIT);
	if (ft_strcmp(command, "unset")) //  sürekli main process. Pipe ile kullanınca çalışmadı linuxta.
        return (UNSET);
	if (ft_strcmp(command, "export")) // sürekli main process. Pipe ile kullanınca çalışmadı linuxta.
        return (EXPORT);
    return (0);

}

void    run_builtin(char **execute, int type)
{
    if (type == CD)
        builtin_cd(execute);
    if (type == ENV)
        builtin_env();
    if (type == PWD)
        builtin_pwd(execute);
    if (type == ECHO)
        builtin_echo(execute);
    if (type == EXIT)
        builtin_exit(execute);
    if (type == UNSET)
        builtin_unset(execute);
    if (type == EXPORT)
        builtin_export(execute);
}