#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	int pid;
	for(int i = 1; i <= 4; i++)
		if(pid = fork() > 0)
			printf("Hi %d  %d\n",getpid(), getppid());
		exit(0);

}
