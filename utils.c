#include <unistd.h>
int ft_atoi(char *str)
{
    int i=0;
    int sign =1;
    int result =0;
    while(str[i] == 32 || (9 <= str[i] && str[i] <= 13))
    i++;
    if(str[i] == '-')
    {
        i++;
        sign *= -1;
    }
    else if( str[i] == '+' )
        i++;
    while('0' <= str[i] && str[i] <= '9')
    {
        result = result * 10 + (str[i] -'0');
        i++;
    }
    return (sign * result);
}

void ft_putnbr(int nbr)
{
  if( nbr >= 10)
  {
    ft_putnbr(nbr / 10);
  }
  char c = nbr % 10 + '0';
  write(1,&c,1);

}

void ft_putstr(char *str)
{
    int i=0;
    while(str[i])
    {
        write(1,&str[i],1);
        i++;
    }
    
}