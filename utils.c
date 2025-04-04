/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 10:08:55 by aoussama          #+#    #+#             */
/*   Updated: 2025/04/05 11:39:42 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

void	chek_pid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			write(1, "Error\nthis pid is not correct:( \n", 34);
			write(1, "please enter only positive number without a sing :) \n",
				54);
			exit(1);
		}
		i++;
	}
}

long	ft_atoi(const char *str)
{
	int	i;
	long	result;

	i = 0;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
        if (result > INT_MAX)
            exit (1);
		i++;
	}
	return (result);
}

void	print_error(void)
{
	write(1, "Error\n this pid is not found:(\n", 32);
	exit(1);
}
