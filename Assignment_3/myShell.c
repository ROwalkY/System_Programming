#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/signal.h>
#include <sys/wait.h>

int readLine(int, char *, int);

int main(int argc, char *argv[]){
  int status=0, n;
  char line[255];

	int fp = open(argv[1],O_RDONLY);

  while(1){
    n=readLine(fp, line, 1);

    if(n<=0){
      break;
    }
    line[n-1]='\0';


		if(line[0] == '#'){
			continue;
		}

    if(!fork()){
			char *myCommand[10];
			char *token;
			int length = 0;
			int wordCount = 0;

      token = strtok(line," ");
    	while(token != NULL){
    		myCommand[wordCount++] = token;
    		token = strtok(NULL," ");
    	}

			for(int i = wordCount; i < 10; i++){ //assign NULL to the unused index
				myCommand[i] = NULL;
			}
      execlp(myCommand[0], myCommand[0],myCommand[1],myCommand[2],myCommand[3],myCommand[4],
		      myCommand[5],myCommand[6],myCommand[7],myCommand[8],myCommand[9], NULL);
    }
    wait(&status);
  }
  if(n==-1)
    perror("Reading error ");
  exit(0);
}

int readLine(int fd, char *buff, int size){

	char buffer;
	char *p_count = buff;	//count the index of *buff

	int count = 0;	//count the total bytes read


	do{
		int flag = read(fd, &buffer, size);

		if(flag == -1){
			return -1;
		}else if(flag == 0)
			return count == 0?0:count;
		else{

			*p_count = buffer;
			p_count++;
			count++;
		}

	}while(buffer != '\n');

	return count;
}
