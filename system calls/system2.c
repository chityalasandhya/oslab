#include<fcntl.h>
	#include<stdio.h>
	#include<stdlib.h>
	#include<unistd.h>
	#include<sys/types.h>
	#include<sys/stat.h>
	static char message[] = "Hello, World\n";
	int main(){
	int fd;
	char buffer[80];
	fd = open("Datafile.dat",O_RDWR|O_CREAT|O_EXCL,S_IREAD|S_IWRITE);
	if(fd != -1){
	printf("Datafile.dat openend for write/write access\n");
	write(fd,message,sizeof(message));
	lseek(fd,0L,0);
	if(read(fd,buffer,sizeof(message)) == sizeof(message))
	printf("\%s\"was written to Datafile.dat\n",buffer);
	else
	printf("***error reading the file\n");
	}
	else
	printf("***Datafile.dat already exists***\n");
	exit(0);
	}


