#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdlib.h>
#define SHMSIZE 27
int main(int argc,char* argv[])
{
        key_t key;
        int shmid;
        char *data;
        int mode;
        if(argc <2)
        {
                fprintf(stderr,"usage :shmdemo\n");
                exit(1);
        }
        if((key=ftok("hello.txt",'r'))==-1)
        {
                perror("ftok");
                exit(1);
        }
        if((shmid=shmget(key,SHMSIZE,0644|IPC_CREAT))==-1)
        {
                perror("shmget");
                exit(1);
        }
        data=shmat(shmid,(void *)0,0);
        if(data==(char *)(-1))
        {
 perror("shmat");
                exit(1);
        }
        if(argc==2)
        {
                printf("\nWriting to segment: %s \n",argv[1]);
                strncpy(data,argv[1],SHMSIZE);
        }
        else
        {
                printf("\nSegment contains : %s \n",data);
        }
        if(shmdt(data)==-1)
        {
                perror("shmdt");
                exit(1);
        }
        return 0;
}
