/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 09:48:58 by aoussama          #+#    #+#             */
/*   Updated: 2025/04/02 09:44:43 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

static int	g_flag;

static void	success(int signl)
{
	g_flag = 1;
	(void)signl;
}

static void	send_bit(char character, int pid)
{
	int (bit), ascii, timer = 500;
	ascii = (int)character;
	bit = 0;
	while (bit < 8)
	{
		if (((ascii >> bit) & 1) == 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				print_error();
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				print_error();
		}
		bit++;
		while (!g_flag)
		{
			usleep(200);
			timer--;
			if (timer == 0)
				exit(1);
		}
		g_flag = 0;
	}
}

int	main(int ac, char **av)
{
	int	i;
	int	pid;

	i = 0;
	if (ac != 3)
	{
		write(2, "Enter pid and message\n", 23);
		return (1);
	}
	chek_pid(av[1]);
	pid = ft_atoi(av[1]);
	signal(SIGUSR1, success);
	while (av[2][i])
	{
		send_bit(av[2][i], pid);
		i++;
	}
	return (0);
}
