#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
int main(int argc, char *argv[]){ 
	printf("One "); 
	fork(); 
	printf("Windsor\n"); 
	pause(); 
	printf("Two\n"); 
	exit(0);
}
