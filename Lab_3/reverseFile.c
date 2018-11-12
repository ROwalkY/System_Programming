#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argv, char *argc[]){

	if(argv != 3){
		printf("Correct call: %s <inputFilenName> <outputFileName>",argc[0]);
	}else{
		FILE *fp1, *fp2;
		char buffer[256];

		fp1 = fopen(argc[1],"r");

		fp2 = fopen(argc[2], "w");

		if(!fp1 || !fp2){

			printf("File open error\n");
			exit(0);
		}else{

			int filesize;

			fseek(fp1,0,SEEK_END);
			filesize = ftell(fp1);
			rewind(fp1);

			fseek(fp2,filesize,SEEK_SET);
			while(fgets(buffer,255,fp1)){
				int length = strlen(buffer);
				fseek(fp2,-length,SEEK_CUR);
				fputs(buffer,fp2);
				fseek(fp2,-length,SEEK_CUR);

			}

		}

	}
	return 0;

}
