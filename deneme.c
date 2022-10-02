#include "minishell.h"

int main ()
{
	pid_t pid;
	char *str[4] = { "ls", "-l", NULL };

	pid = fork();
	if (pid == 0)
	{
		execve("/bin/lss", str, NULL);
		printf("Geliyor Ssanki \n");
	}

		wait(NULL);
		printf("Geldi\n");
	
}