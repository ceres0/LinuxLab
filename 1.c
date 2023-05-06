#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main(void)
{
	pid_t pid = 1000;
	int count = 0;
	int a;
	pid = fork();
	printf("\n Now,the pid returned by calling fork() is %d\n", pid);
	if (pid > 0) //   parent
	{
		printf("It is the parent process,the  pid of child:%d\n", pid);
	}
	else if (!pid) // pid==0   is child
	{
		printf("This is the child process.\n");
	}
	else // pid<0  failed
	{
		printf("fork failed.\n");
	}
	return 0;
}
