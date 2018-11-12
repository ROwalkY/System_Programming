#include <stdio.h>
#include <unistd.h>
int main(){

	int pid;
	int ppid;

	if(fork() == 0){
		printf("The child process pid is %d\n",getpid());
		printf("The child process ppid is %d\n",getppid());

	}else{
		if(fork() == 0){
			printf("The child process pid is %d\n",getpid());
			printf("The child process ppid is %d\n",getppid());
		}else{
			printf("The parent process pid is %d\n",getpid());
			printf("The parent process ppid is %d\n",getppid());

		}
	}

	return 0;
}
