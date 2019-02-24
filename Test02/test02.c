#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(void){
	if(!fork()){
		sleep(4); 
		printf("Monday");
	}else{
//		alarm(1); 
		sleep(2); 
		printf("November "); 
	}
	exit(0);
}
