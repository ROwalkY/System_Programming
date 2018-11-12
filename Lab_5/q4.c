#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/signal.h>
#include <sys/wait.h>
int readLine(int, char *, int);

int main(int argc, char *argv[]){ // To execute
  int status=0, n; // commands with no arguments
  char line[255];
  char prompt[30]="Enter your command here> ";
  while(1){
    write(STDIN_FILENO, prompt, 25);
    n=readLine(STDIN_FILENO, line, 255);
    if( n <= 0) // read a command
       break;
    line[n-1]='\0'; // get rid of \n and add '\0'
                        // for string manipulation
    if(!fork()){
	char *array[10];
	char *token;
	int wordCount = 0;
	token = strtok(line," ");
	while(token != NULL){

		printf("%s\n",token);
		array[wordCount++] = token;
		token = strtok(NULL," ");
	}
	printf("%d\n",wordCount);
	for(int i = wordCount; i < 10; i++){
		array[i] = NULL;
	}
       	execlp(array[0], array[0],array[1],array[2],array[3],array[4],
		array[5],array[6],array[7],array[8],array[9], NULL);
    }
    wait(&status);
  }
  if(n==-1)
    perror("Reading error ");
  exit(0);
}
int readLine(int fd, char *buff, int n){
  int i=0, m;
  while(i<n && (m=read(fd, &buff[i], 1))==1){
    if(buff[i]=='\n')
       return(i+1);
    i++;
  }
  if(m == -1) // Error, return -1
     return(-1);
  else
     return(i); // number of characters read
}
