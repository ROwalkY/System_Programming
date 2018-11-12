#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){

	float a,b;
	char op;
	FILE *f;
	float sum;
	if(fork()){
		while(f=fopen("temp.txt","r")){
			fclose(f);
			sleep(1);
		}
		scanf("%f %f %c",&a,&b,&op);
		f = fopen("temp.txt","w");
		fprintf(f,"%f %f %c\n",a,b,op);
		fclose(f);
		sleep(3);
	}else{
		while(!(f=fopen("temp.txt","r"))){
			sleep(1);
		}
		fscanf(f,"%f %f %c",&a,&b,&op);

		if(op == '+'){
			sum = a+b;
		}else if(op == '-'){
			sum = a - b;
		}else if(op == '*'){
			sum = a*b;
		}else if(op == '/'){
			sum = a/b;
		}else{

		}
		fprintf(stderr,"%.2f",sum);
		fclose(f);
		unlink("temp.txt");
		sleep(1);
	}
	exit(0);

}

