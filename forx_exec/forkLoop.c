#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
	//Try the cmd line ps f -a tp see the tree of processes
/*
for example:
6849 pts/2    S+     0:00 ./forkLoop  //has 3 iterations left
 6850 pts/2    S+     0:00  \_ ./forkLoop 	//has 2 iterations left
 6852 pts/2    S+     0:00  |   \_ ./forkLoop	//has 1 iterations left
 6856 pts/2    S+     0:00  |   |   \_ ./forkLoop  //has 0 iterations left
 6855 pts/2    S+     0:00  |   \_ ./forkLoop	//has 0 iterations left
 6851 pts/2    S+     0:00  \_ ./forkLoop	//has 1 iterations left
 6854 pts/2    S+     0:00  |   \_ ./forkLoop
 6853 pts/2    S+     0:00  \_ ./forkLoop	//has 0 iterations left
Note that it's 2^n processes
*/
	for(int i = 0; i < 3; ++i)
	{
		fork();
		printf("I'm %d\n", (int) getpid());
	}
	sleep(30);
	printf("***  I'm %d\n", (int) getpid());
	return 0;
}

