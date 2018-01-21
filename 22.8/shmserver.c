#include<sys/types.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#define SHMSZ 27
void die(char *s)
{
        perror(s);
        exit(1);
}
int main()
{
        char c;
        int shmid;
        key_t key;char *shm,*s;key=5678;
        if((shmid=shmget(key,SHMSZ,IPC_CREAT|0666))<0)
        {
                die("shmget");
        }
        if((shm=shmat(shmid,NULL,0))==(char*)-1)
        {
                die("shmat");
        }
        printf("Sending...");
        s=shm;
        for(c='a';c<='z';c++)
                *s++=c;
        s=NULL;
        while(*shm!='*')
                sleep(1);
        exit(0);
 return 0;
}
