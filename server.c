/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 09:49:30 by aoussama          #+#    #+#             */
/*   Updated: 2025/04/02 09:56:50 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

static void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

static void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-n, fd);
	}
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}

static void	handle_signal(int sig, siginfo_t *info, void *ucontext)
{
	static pid_t	pid_clt;
	static int		bit;
	static char		character;

	(void)ucontext;
	if (pid_clt != info->si_pid)
	{
		pid_clt = info->si_pid;
		character = 0;
		bit = 0;
	}
	if (sig == SIGUSR1)
	{
		character |= (1 << bit);
	}
	bit++;
	if (bit == 8)
	{
		write(1, &character, 1);
		character = 0;
		bit = 0;
	}
	usleep(20);
	kill(pid_clt, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	write(1, "(PID): ", 8);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	sa.sa_sigaction = handle_signal;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	while (1)
	{
		pause();
	}
}
