#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
void CTR_handler(){ 
	printf("Process %d got a CTR-C, exit\n", getpid()); 
	exit(0);
}
int main(int argc, char *argv[]){ 
		int i, pid;
		signal(SIGINT,CTR_handler); 
		if((pid=fork()) == 0){ 
			setpgid(0, getpid());//child is in its own group
			printf("PID=%d, PGID=%d\n",getpid(),getpgid(0));
		}else
			printf("PID=%d, PGID=%d\n", getpid(), getpgid(0)); 
		for(i=1; i<=10; i++){ 
			printf("Process %d is still alive\n", getpid()); 
			sleep(2);
		}
}
