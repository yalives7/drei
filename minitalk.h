
#ifndef MINITALK_H
#define MINITALK_H
#include <signal.h>// daha da gelissin kalkacak zaten eheheh
typedef struct s_data
{
	int		counter;
	unsigned char 	character;
}	t_data;

int ft_atoi(char *str);
void ft_putnbr(int nbr);
void ft_putstr(char *str);

#endif