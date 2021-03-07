#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

//int i=0; //global, yet each process has it's own address space

void doSomeWork(char *pName)
{
	const int NUM_TIMES = 2;
	for(int i=0; i < NUM_TIMES; ++i)
	{
		sleep(rand() % 4);
		printf("Done iteration %d, for %s\n", i, pName);
	}
}


int main(void)
{
	printf("I'm %d\n", (int)getpid());

	pid_t pid = fork();
	srand((int) pid);//To randomize in each run, and each process
	printf("Fork returned %d\n", (int) pid);
	
	if(pid < 0)
	{
		printf("Fork failed\n");
	}
	if(pid == 0)
	{
		printf("I'm a child, with pid = %d\n", (int)getpid());
		doSomeWork("Child");
		exit(0);
	}
	
	//If we got here, we must be the parent
	printf("I'm the parent, with pid = %d, waiting for the child to end\n", (int)getpid());
	sleep(10);	
	doSomeWork("Parent");	
	int status = 0;
	pid_t childPid = wait(&status);
	int childReturnValue = WEXITSTATUS(status);
	printf("Parent know that child %d finished with status %d\n",
				 childPid, childReturnValue);
	return 0;
}
