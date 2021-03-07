#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int global = 20; //will always be 20, as a new one with each exec

int main(int argc, char** argv)
{
	printf("selfExec.c:");
	printf(" My PID %d\n", (int) getpid());
	printf("    global = %d\n", global);
	--global;
	if(argc != 2)
	{
		printf("pass 1 ineger argument\n");
		exit(1);
	}
	int n = atoi(argv[1]);
	printf("%d....\n", n);
	if(n != 0)
	{
		char nMinus1[10];
		sprintf(nMinus1, "%d", n-1);
		execlp(argv[0], argv[0], nMinus1, NULL);
	}
	
	//We'll never reach this point
	printf("Done With execTry.c: \n");
	return 0;
}
