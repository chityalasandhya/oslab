#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
	char wtmsg[2][20] = {"hello","hi"};
	char rdmsg[20];
	int pfd[2],retstatus;
	int pid;
	retstatus = pipe(pfd);
	if(retstatus == -1){
		printf("pipe is unable to create\n");
		return 1;
	}
	pid = fork();
	if(pid == 0)
	{
	printf("writing from the file %s\n",wtmsg[0]);
	write(pfd[1],wtmsg[0],sizeof(wtmsg[0]));
	printf("wrting from file 1 %s\n",wtmsg[0]);
	write(pfd[1],wtmsg[1],sizeof(wtmsg[1]));
	printf("writing from file 2 %s\n",wtmsg[1]);
	}
	else{
	read(pfd[0],rdmsg,sizeof(rdmsg));
	printf("reading from file %s\n",rdmsg);
	read(pfd[0],rdmsg,sizeof(rdmsg));
	printf("reading from file 2 %s\n",rdmsg);
	}
	return 0;	
	}
	
	

