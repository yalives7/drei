#include "minitalkbonus.h"
#include <unistd.h>


void handler(int sig)
{
    if( sig == SIGUSR1)
        write(1,"mesaj ulasti",12);
    
}


void send_bits(char byte, int server_pid)
{
    int i=7;
    while( i >= 0)
    {
        if(byte >> i & 1 )
            kill(server_pid,SIGUSR1);
        else
            kill(server_pid,SIGUSR2);
        usleep(100);
        i--;    
    }
}


void send_bytes(char *message,int server_pid)
{
    int i=-1;
    while(message[++i])
        send_bits(message[i],server_pid);
}


int main(int ac ,char **av)
{

    if( ac != 3)
    {
        write(1,"./client [sunucu PID] [mesaj]",31);
    }
    int server_pid = ft_atoi(av[1]);
    signal(SIGUSR1, handler);
    signal(SIGUSR2, handler);
    send_bytes(av[2],server_pid);
    

}