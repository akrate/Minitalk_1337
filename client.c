/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 09:48:58 by aoussama          #+#    #+#             */
/*   Updated: 2025/01/21 22:03:44 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
int	ft_atoi(const char *str)
{
	int	i;
	int	sin;
	int	result;

	i = 0;
	sin = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		sin *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result * sin);
}
void send_bit(char character, int pid)
{
    int bit = 0;
    int ascii;
    ascii = (int)character;
    while(bit < 8)
    {
        if((ascii >> bit)&1)
        {
            kill(pid, SIGUSR1);
        }
        else
            kill(pid, SIGUSR2);
        usleep(500);
        bit++;
    }
    
}

int main(int ac,char **av)
{
    int i;
    int pid;

    i = 0;
    if (ac == 3)
    {
        pid = ft_atoi(av[1]);
        while (av[2][i])
        {
            send_bit(av[2][i],pid);
            i++;
        }
    }
}