#include<stdio.h>
#include<fcntl.h>
void main()
{
 int fd=creat("file1.txt",O_WRONLY);
 printf("fd=%d",fd);
}
