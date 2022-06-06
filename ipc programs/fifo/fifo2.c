#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
        int fd1;
        char *myfifo = "/tmp/myfifo";
        mkfifo(myfifo,0666);
char arr1[80],arr2[80];
while(1)
{
fd1 = open(myfifo,O_RDONLY);
read(fd1,arr1,80);
printf("user1:%s/n",arr1);
close(fd1);
        fd1 = open(myfifo,O_WRONLY);
        fgets(arr2,80,stdin);
write(fd1,arr2,strlen(arr2)+1);
close(fd1);
}
return 0;
}

