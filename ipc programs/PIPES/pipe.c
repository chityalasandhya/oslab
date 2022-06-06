#include<stdio.h>
#include<unistd.h>
int main() {
	int pipefds1[2], pipefds2[2];
	int returnstatus1, returnstatus2;

	int pid;
	char pipe1wtmsg[20] = "Hi";
	char pipe2wtmsg[20] = "Hello";
	char readmsg[20];
	returnstatus1 = pipe(pipefds1);
	if (returnstatus1 == -1) {
	printf("Unable to create pipe 1 \n");
	return 1;
	}
	returnstatus2 = pipe(pipefds2);
	if (returnstatus2 == -1) {
	printf("Unable to create pipe 2 \n");
	return 1;
	}
		pid = fork();
		if (pid != 0)  {
			close(pipefds1[0]); 
			close(pipefds2[1]); 
			printf("In Parent: Writing to pipe 1 – Message is %s\n",pipe1wtmsg);
			write(pipefds1[1], pipe1wtmsg,sizeof(pipe1wtmsg));
			read(pipefds2[0], readmsg, sizeof(readmsg));
			printf("In Parent: Reading from pipe 2 – Message is %s\n",readmsg);
			} else { 
				close(pipefds1[1]); // Close the unwanted pipe1 write side
				close(pipefds2[0]); // Close the unwanted pipe2 read side
				read(pipefds1[0], readmsg, sizeof(readmsg));
				printf("In Child: Reading from pipe 1 – Message is %s\n",readmsg);
				printf("In Child: Writing to pipe 2 – Message is %s\n",pipe2wtmsg);

				write(pipefds2[1], pipe2wtmsg,sizeof(pipe2wtmsg));
				}
				return 0;
}

