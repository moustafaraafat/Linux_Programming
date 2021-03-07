#include <stdio.h>
#include <unistd.h>

int main(int argc, char** argv)
{
	printf("HelloExec.c: \n");
	printf("   My PID %d\n", (int) getpid());

	printf("My Arguments:  ");
	for(int i = 0; i < argc; ++i)
	{
		printf("%s, ", argv[i]);
	}
	
	printf("\n");
	
	return 0;
}
