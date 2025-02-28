#include "minitalkbonus.h"
#include <unistd.h>

typedef struct s_data {
    int bit;
    int client_pid;
    char c;
} t_data;

t_data g_data;

void reset_data(void) {
    g_data.bit = 128;
    g_data.client_pid = 0;
    g_data.c = 0;
}

void handler(int sig, siginfo_t *info, void *ucontext) {
    (void)ucontext;
    if (g_data.client_pid != info->si_pid) {
        reset_data();
    }
    if (sig == SIGUSR1) {
        g_data.c += g_data.bit;
    }
    g_data.bit /= 2;
    if (g_data.bit == 0) {
        if (g_data.c == '\0') {
            kill(info->si_pid, SIGUSR2);
        }
        write(1, &g_data.c, 1);
        reset_data();
    }
    g_data.client_pid = info->si_pid;
}

int main(void) {
    struct sigaction sa;
    ft_putstr("pid :    ");
    ft_putnbr(getpid());
    ft_putstr("\n");
    sa.sa_sigaction = &handler;
    sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    while (1) {
        sleep(1);
    }
}