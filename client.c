#include "minitalk.h"
#include <stdlib.h>
#include <unistd.h>
void send_bit(char byte,int server_pid)
{
    int i = 7;
    while(i >= 0)
    {
       if( byte >> i &1)
        kill(server_pid,SIGUSR1);
       else
        kill(server_pid,SIGUSR2);

    usleep(100);
        i--;
    }
}

void send_byte(char *str, int server_pid)
{
    int i=-1;
    while(str[++i])
    {
        send_bit(str[i],server_pid);
        
    }
}


int main(int ac , char **av)
{
    int server_pid=0;
    if( ac != 3)
    {
        if(server_pid <= 0)
            ft_putstr("geçersiz bir PIDdir");
        
    }
   else if ( ac == 3)
   {
    server_pid = ft_atoi(av[1]);
     send_byte(av[2],server_pid);
   }
   
    
}