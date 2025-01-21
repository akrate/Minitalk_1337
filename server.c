/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 09:49:30 by aoussama          #+#    #+#             */
/*   Updated: 2025/01/21 22:07:30 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void handle_signal(int sig) {
    static int bit = 0;
    static char character = 0;


    if (sig == SIGUSR1) {
        character |= (1 << bit);
    }
    bit++;
    if (bit == 8) { 
        write(1, &character, 1); 
        character = 0;           
        bit = 0;            
    }
}

int main() {
   
    printf("(PID): %d\n", getpid());
    signal(SIGUSR1, handle_signal);
    signal(SIGUSR2, handle_signal);
    while (1)
        pause(); 
    return 0;
}