#include "minishell.h"

int main()
{
    int     fd[2];
    int     fd2[2];
    char    str[20];

    pipe(fd);
    pipe(fd2);
    dup2(fd2[1], fd[1]);

    int pid = fork();
    if (pid == CHILD_PROCESS)
    {
        dup2(fd[1], 1);
        write(1, "deneme\n", 7);
        exit(0);
    }
    wait(NULL);
    read(fd2[0], str, 6);
    str[7] = 0;
    printf("STR: %s\n", str);

}