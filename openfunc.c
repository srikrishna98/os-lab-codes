#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
extern int errno;
int main()
{
 int fd=open("file.txt",O_RDONLY|O_CREAT);
 printf("fd=%d\n",fd);
 if(fd==-1)
 {
 	printf("Error number:%d\n",errno);
	perror("program");
 }
 return 0;
}
