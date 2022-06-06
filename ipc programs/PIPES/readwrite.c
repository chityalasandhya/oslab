#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
int pipefds[2],returnval;
char writemsg[2][20]={"HELLO","WORLD"};
char readmsg[20];
returnval=pipe(pipefds);
if(returnval==-1){
printf("Cant create a pipe");
return 1;
}
printf("Writing\n");
printf("message 1: %s\n",writemsg[0]);
write(pipefds[1],writemsg[0],sizeof(writemsg[0]));
printf("written message 1 is %s\n",writemsg[0]);
write(pipefds[1], writemsg[1], sizeof(writemsg[1]));
printf("written message 2 is %s",writemsg[1]);
printf("\nReading");
read(pipefds[0], readmsg, sizeof(readmsg));
printf("\nread message 1 is %s", readmsg);
read(pipefds[0], readmsg, sizeof(readmsg));
printf("\nread message 2 is %s\n", readmsg);
return 0;
}

