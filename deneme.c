#include "minishell.h"

int main()
{
    int     fd[2];
    int     fd2[2];

    pipe(fd);
    pipe(fd2);

    int pid = fork();
    if (pid == CHILD_PROCESS)
    {
        dup2(fd[1], 1);
        close(fd[0]);
        close(fd[1]);
        close(fd2[0]);
        close(fd2[1]);
        execlp("echo", "echo", "\n", "deneme", "\n", "abc", "\n", "123", NULL);

    }

    int pid2 = fork();
    if (pid2 == CHILD_PROCESS)
    {
        dup2(fd[0], 0);
        dup2(fd2[1], 1);
        close(fd[0]);
        close(fd[1]);
        close(fd2[0]);
        close(fd2[1]);
        execlp("grep", "grep", "abc", NULL);
    }

    int pid3 = fork();
    if (pid3 == CHILD_PROCESS)
    {
        dup2(fd2[0], 0);
        close(fd[0]);
        close(fd[1]);
        close(fd2[0]);
        close(fd2[1]);
        execlp("grep", "grep", "abc", NULL);
    }

    close(fd[0]);
    close(fd[1]);
    close(fd2[0]);
    close(fd2[1]);

    wait(NULL);
    wait(NULL);
    wait(NULL);

}