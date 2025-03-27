/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 18:22:07 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/27 19:12:21 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <readline/readline.h>
#include <sys/wait.h>
#include <sys/ioctl.h>

volatile sig_atomic_t g_sig = 0;

// Function to handle SIGINT in the child process
void st_sig_int(int sig)
{
	g_sig = sig;
	printf("CTRL+C signal received, exiting HEREDOC\n");
	ioctl(0, TIOCSTI, "\n"); 
}

int main()
{
    char *input;
    
	signal(SIGINT, st_sig_int);
    input = readline("heredoc> ");
	if (g_sig != 0)
		printf("Custom code\n");
	printf("Input:%s\n", input);
	free(input);
    return 0;
}