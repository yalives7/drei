
#include "minitalkbonus.h"
#include <unistd.h>
t_data	g_data;

void	reset_data(void)
{
	
	g_data.bit = 128;
	g_data.client_pid = 0;
}

void	handler(int sig, siginfo_t *info, void *ucontext)
{
    g_data.bit = 128;
	(void)ucontext;
	if (g_data.client_pid != info->si_pid)
		reset_data();
	char c = 0;
    if(sig == SIGUSR1)
        c = c + g_data.bit;
    g_data.bit/= 2;
	if ( g_data.bit == 0)
	{
		if (g_data.bit == 0)
			kill(info->si_pid, SIGUSR2);
		write(1, &c, 1);
		reset_data();
	}
	g_data.client_pid = info->si_pid;
}

int	main(void)
{
	struct sigaction	sa;

	reset_data();
	ft_putstr("pid :    ");
	ft_putnbr(getpid());
	ft_putstr("\n");
	sa.sa_sigaction = &handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		sleep(1);
}