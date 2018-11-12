#include<stdlib.h>
#include <unistd.h>
#include <fcntl.h>
int readInt();
void printInt(int);
int main(int argc, char *argv[]){
	int intNum1, intNum2, intSum;
  	char message1[20]="Enter an integer> ";
	char message2[40]="the sum of the two numbers is: ";

	write(STDOUT_FILENO, message1, 18);
	intNum1 = readInt();

	write(STDOUT_FILENO, message1, 18);
	intNum2 = readInt();

 	intSum = intNum1+intNum2;
	write(STDOUT_FILENO, message2, 32);
	printInt(intSum);
	exit(0);

}
int readInt(){ //complete the code
	char number[10];
	int i=0, val=0; 
	char message[40]="Invalid integer, start over again\n";

	read(STDOUT_FILENO, number, 10); // read an integer as a string (line)

	while(number[i] != '\n'){
    		if( number[i] < '0' || number[i] > '9'){ // case of nondigit characters
	      	write(STDOUT_FILENO, message, 35);
      		exit(1);
  	  	}
    	val = val * 10 + (number[i]-'0'); // conversion of a string into an int
    	i++;
  	}
  	return(val);
}

void printInt(int val){
	char number[11];
	int i=10;
  	number[10]='\n'; // needed to go next line
  	do{
    		i--;
	    	number[i]= '0' + val%10; // get ASCII code of left most digit
    		val = val / 10; // get rid of the right most digit
  	}while(val != 0 );
  	write(STDOUT_FILENO, &(number[i]), 11-i); // print starting at address
}                                             // of first digit
