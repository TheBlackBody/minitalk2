
#include "../minitalk.h"

void	error(int pid, char *str)
{
	if (str)
		free(str);
	ft_printf("unexpected error \n");
	kill(pid, SIGUSR2);
	exit(EXIT_FAILURE);
}

char	*print_string(char *message)
{
	ft_printf("%s\n", message);
	free(message);
	return (NULL);
}

void	handler_sigusr(int signum, siginfo_t *info, void *context)
{
	static char	c;
	static int	bits;
	static int	pid;
	static char	*message;

	if (!pid)
	{
		c = 0xFF;
		bits = 0;
		pid = 0;
		message = 0;
	}
	(void)context;
	if (info->si_pid)
		pid = info->si_pid;
	if (signum == SIGUSR1)
		c ^= 0x80 >> bits;
	else if (signum == SIGUSR2)
		c |= 0x80 >> bits;
	if (++bits == 8)
	{
		if (c)
			message = ft_stradd_c(message, c);
		else
			message = print_string(message);
		bits = 0;
		c = 0xFF;
	}
	if (kill(pid, SIGUSR1) == -1)
		error(pid, message);
}

int	main(void)
{
	struct sigaction	sa_signal;
	sigset_t			block_mask;

	sigemptyset(&block_mask);
	sigaddset(&block_mask, SIGINT);
	sigaddset(&block_mask, SIGQUIT);
	sa_signal.sa_handler = 0;
	sa_signal.sa_flags = SA_SIGINFO;
	sa_signal.sa_mask = block_mask;
	sa_signal.sa_sigaction = handler_sigusr;
	sigaction(SIGUSR1, &sa_signal, NULL);
	sigaction(SIGUSR2, &sa_signal, NULL);
	ft_printf("PID: %i \nWaiting message ...\n", getpid());
	while (1)
		pause();
}
