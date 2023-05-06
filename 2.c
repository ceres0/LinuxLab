#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main(void)
{
	pid_t pid;
	int count = 0;
	int a;
	pid = fork();
	printf("\n Now,the pid returned by calling fork() is %d\n", pid);
	if (pid > 0) //   parent
	{
		printf("It's the parent process,the pid of child:%d\n", pid);
		printf("In the parent process,count = %d\n", count);
		scanf("%d", a);
	}
	else if (!pid) // pid==0   is child
	{
		printf("This is the child process.\n");
		printf("Do your own things here.\n");
		count++;
		printf("In the child process, count = %d\n", count);
		// scanf("%d",a);
	}
	else // pid<0  failed
	{
		printf("fork failed.\n");
	}
	return 0;
}
