#include<stdio.h>
#include<sys/msg.h>
#include<stdlib.h>
#include<string.h>
#include<sys/msg.h>
int main()
{
        //char msg[100];
//        int msgid=1000;

        int msgid=msgget((key_t)1234,0644|IPC_CREAT);
        struct message
        {
                long type;
                char text[20];
        }msg;
        msg.type=1;
        strcpy(msg.text,"Message 1");
        if(msgsnd(msgid,(void *)&msg,sizeof(msg.text),IPC_NOWAIT)==-1)
        {

                fprintf(stderr,"failed to send:\n");
                exit(1);
        }
        return 0;
}