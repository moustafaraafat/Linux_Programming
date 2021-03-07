#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv)
{
	printf("execTry.c: \n");
	printf("   My PID %d\n", (int) getpid());

	char *args[] = {"./HelloExec", "Hello", "World",  NULL};
	execvp(args[0], args);
	//We'll never reach this point
	printf("Done With execTry.c: \n");
	return 0;
}
