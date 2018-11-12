#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>	//needed for write()
#include <sys/errno.h>	//needed for perror()
#include <fcntl.h>	//needed for oflag

//Function Prototype
int readLine(int fd, char *buff, int size);
void checkSINValid(char *buff, char *message,int *decode, int sin_length);

int main(int argc, char *argv[]){

	int decodeArray[] = {1,2,1,2,1,2,1,2,1};
	char message[10] = "VALID";
	char buffer[11];//store the 9 digit SIN code and 1 digit "\n" and extra 1 for \0

	int fp = open(argv[1], O_RDONLY);

	if(fp == -1){
		perror("\nCannot open the file");
		exit(1);
	}else{
		int counter = readLine(fp,buffer,1);

		do{
			int sin_Length = counter - 1;

			checkSINValid(buffer,message,decodeArray,sin_Length);

			counter = readLine(fp,buffer,1);//read again

		}while(counter != 0);
	}

	close(fp);
	return 0;
}

//INPUT: file pointer *fd, String buffer *buff, size of the item
//OUTPUT: return how many bytes read, return -1 for errors and 0 for end-of-file
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

//Print out if the SIN is valid
//INPUT: a char pointer variable *buff that stored SIN number,
//		a char pointer variable *message that has the message to print out
//		a int variable indicate the length of the SIN number
//OUTPUT: a sequence of SIN number followed by the status of the SIN
//		NON VALID if not, otherwise VALID
void checkSINValid(char *buff, char *message, int *decode, int sin_length){

		int current_num;
		int sum = 0;

		write(STDIN_FILENO,buff, sin_length);
		write(STDIN_FILENO,"\t",1);

		if( sin_length < 8){
			write(STDIN_FILENO,"\t",1);
		}//extra tab for shorter sequence

		if( sin_length != 9){
			write(STDIN_FILENO,"NON ",4);
		}else{

			for(int i = 0; i < sin_length; i++){

				current_num = (*(buff+i) - '0') * (*(decode+i)) ;
				if(current_num > 9){
					current_num = current_num/10 + current_num%10;
				}
				sum += current_num;
			}
			if(sum%10 != 0){
				write(STDIN_FILENO,"NON ",4);
			}
		}
			write(STDIN_FILENO,message,5);
			write(STDIN_FILENO,"\n",1);
}
