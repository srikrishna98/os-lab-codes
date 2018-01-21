#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<unistd.h>
#include<sys/msg.h>

//#define BUFSIZ 100
struct my_msg_st
{
        long int my_msg_type;char some_text[BUFSIZ];
};
int main()
{
        int running=1;int msgid;struct my_msg_st some_data;
        long int msg_to_receive=0;
        msgid=msgget((key_t)1234,0666|IPC_CREAT);
        if(msgid==-1)
        {
                fprintf(stderr,"failed to get:\n");
                exit(EXIT_FAILURE);
        }
        while(running)
        //if(running==1)
        {
                if(msgrcv(msgid,(void*)&some_data,BUFSIZ,msg_to_receive,0)==-1)
                {

                fprintf(stderr,"failed to receive:\n");
                exit(EXIT_FAILURE);
                }
printf("You wrote:%s",some_data.some_text);
                if(strncmp(some_data.some_text,"end",3)==0)
                        running=0;
        }
        if(msgctl(msgid,IPC_RMID,0)==-1)
        {
                fprintf(stderr,"failed to delete:\n");
                exit(EXIT_FAILURE);
        }
        exit(EXIT_SUCCESS);
        return 0;
}