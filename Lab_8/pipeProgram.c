#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <time.h>
#include <sys/signal.h>

void buildCommand(char *string,char *comArgv[10]);
void parent(int *fd, char *argv[]);
void child(int *fd, char *argv[]);

int main(int argc, char *argv[]){
  int fd[2];

  //Variable used in strtok
  char *token;
  int count = 0;
  char *commandList[10];

  int status;
  //variable declaration

  //Parsing the string
  token = strtok(argv[1],";");
  while(token != NULL){
    commandList[count++] = token;
    token = strtok(NULL,";");
  }

  char com1[20];
  char com2[20];
  strcpy(com1,commandList[0]);
  strcpy(com2,commandList[1]);

  char *buffer1[10];  //store the first command and arguments
  char *buffer2[10];  //store the second command and arguments

  buildCommand(com1,buffer1);
  buildCommand(com2,buffer2);

  if(fork()){
    parent(fd,buffer1);
  }else{
    child(fd,buffer2);
  }

  wait(&status);
  return 0;
}

void buildCommand(char *string,char *comArgv[10]){
  int count = 0;
  char *token = strtok(string," ");
  while(token != NULL){
    comArgv[count++] = token;
    token = strtok(NULL," ");
  }
  comArgv[count] = NULL;
}

void parent(int *fd, char *argv[]){ // A writer
  close(fd[0]);
  dup2(fd[1], 1); // 1 is the standard output
  close(fd[1]); // close original file descriptor
  if(execlp(argv[0], argv) == -1){
    perror("Cannot exec: ");
    exit(3);
  }
}
void child(int *fd, char *argv[]){ // A reader
  close(fd[1]);
  dup2(fd[0], 0); // 0 is the standard input
  close(fd[0]); // close original file descriptor
  if(execvp(argv[0], argv) == -1){
    perror("Cannot exec: ");
    exit(3);
  }
}
