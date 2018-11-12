#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
int main(){


	char buffer[255];
	char buff;
	char count = 0;
	int fd = open("file.txt",O_RDONLY);
	int status;
	if(fork() == 0){

		while(read(fd,&buff,1)){
			buffer[count] = buff;
			count++;
		}
		write(STDOUT_FILENO,buffer,strlen(buffer));
		sleep(5);
		printf("Child terminating\n");
		sleep(5);
		exit(20);

	}else{

		wait(&status);
		if(status > 0){
			if(WIFEXITED(status)){
				printf("My child has terminated, the status is %d",WEXITSTATUS(status));
			}

		}
	//	wait(NULL);
	}

}

