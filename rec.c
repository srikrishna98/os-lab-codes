#include<stdio.h>
#include<sys/msg.h>
#include<stdlib.h>
#include<stdio.h>
#include<sys/msg.h>
#include<stdlib.h>
#include<sys/msg.h>
int main()
{
//        int msgid=1000;

        int msgid=msgget((key_t)1234,0644|IPC_CREAT);
        struct message
        {
                long type;
                char text[20];
        }msg;
        long msgtype=0;
        if(msgrcv(msgid,(void *)&msg,sizeof(msg),msgtype,0)==-1)
        {
                fprintf(stderr,"failed to receive:\n");
                exit(EXIT_FAILURE);
                }
        printf("%s\n",msg.text);
        return 0;
}
