#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
void buildCommand(char *string,char *comArgv[10]);

int main(int argc, char *argv[]){
  char *token;
  int count = 0;
  char *commandList[10];
  int status;
  token = strtok(argv[1],";");
  while(token != NULL){
    commandList[count++] = token;
    token = strtok(NULL,";");
  }
  char com1[20];
  char com2[20];
  strcpy(com1,commandList[0]);
  strcpy(com2,commandList[1]);
  char *buffer1[10];
  char *buffer2[10];
  int counter = 0;
  printf("First command: %s\n",com1);
  printf("Second command:%s\n",com2);
  buildCommand(com1,buffer1);
  buildCommand(com2,buffer2);
  printf("First command is made up with: \n");

  while(buffer1[counter] != NULL){
    printf("%s\n",buffer1[counter]);
    counter++;
  }

  printf("Second command is made up with: \n");
  counter = 0;
  while(buffer2[counter] != NULL){
    printf("%s\n",buffer2[counter]);
    counter++;
  }
  if(!fork()){
    execvp(buffer1[0],buffer1);
  }
  if(!fork()){
    execvp(buffer2[0],buffer2);
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
