
#include "../minitalk.h"

void	error(char *str)
{
	if (str)
		free(str);
	ft_printf("unexpected error.\n");
	exit(EXIT_FAILURE);
}

int	send_null(int pid, char *str)
{
	static int	i;
	if (!i)
		i = 0;
	
	if (i++ != 8)
	{
		if (kill(pid, SIGUSR1) == -1)
			error(str);
		return (0);
	}
	return (1);
}

int	send_bit(int pid, char *str)
{
	static char	*message;
	static int	s_pid;
	static int	bits;

	if (!s_pid)
	{
		message = 0;
		s_pid = 0;
		bits = -1;
	}
	if (str)
		message = ft_strdup(str);
	if (!message)
		error(0);
	if (pid)
		s_pid = pid;
	if (message[++bits / 8])
	{
		if (message[bits / 8] & (0x80 >> (bits % 8)))
		{
			if (kill(s_pid, SIGUSR2) == -1)
				error(message);
		}
		else if (kill(s_pid, SIGUSR1) == -1)
			error(message);
		return (0);
	}
	if (!send_null(s_pid, message))
		return (0);
	free(message);
	return (1);
}

void	handler_sigusr(int signum)
{
	int	end;

	end = 0;
	if (signum == SIGUSR1)
		end = send_bit(0, 0);
	else if (signum == SIGUSR2)
	{
		exit(EXIT_FAILURE);
	}
	if (end)
	{
		exit(EXIT_SUCCESS);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3 || !ft_str_isnumeric(argv[1]))
	{
			ft_printf("client: invalid arguments.\n");
		ft_printf("Error: [./client <PID> <STR>].\n");
		exit(EXIT_FAILURE);
	}
	signal(SIGUSR1, handler_sigusr);
	signal(SIGUSR2, handler_sigusr);
	send_bit(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
}
