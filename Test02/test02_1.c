#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
int main(){ 
	if(!fork()){ 
		sleep(4);
	 	printf("Monday,%d %d\n",getpid(),getppid());
	}else{
		alarm(3); 
		sleep(2); 
		printf("November,%d %d\n",getpid(),getppid());
		exit(0);
	}
}
