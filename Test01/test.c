#include <stdlib.h>
#include <stdio.h>
int main(int argc, char *argv[]){ 
	//FILE *f;
	char c[20] ="Today is a new day"; 
	//f=fopen(argv[1], "w");
	/*while((c=getchar()) != EOF) {
		fputc(c, stderr);
		//fputc(c,stdout);
		fflush(stdout);
	}*/
	int i = 0;
	while(1){
		if(i == 18){
			break;
		}
		fputc(c[i++],stdout);
	}
	exit(0);
}
