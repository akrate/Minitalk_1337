/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_talk.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 22:13:14 by aoussama          #+#    #+#             */
/*   Updated: 2025/04/02 09:30:06 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_TALK_H
# define NIMI_TALK_H

# include <limits.h>
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_atoi(const char *str);
void	chek_pid(char *str);
// void	ft_putchar_fd(char c, int fd);
// void	ft_putnbr_fd(int n, int fd);
void	print_error(void);

#endif