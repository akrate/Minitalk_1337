/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_talk.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 22:13:14 by aoussama          #+#    #+#             */
/*   Updated: 2025/04/05 11:40:03 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_TALK_H
# define MINI_TALK_H

# include <limits.h>
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

long		ft_atoi(const char *str);
void	chek_pid(char *str);
void	print_error(void);

#endif
