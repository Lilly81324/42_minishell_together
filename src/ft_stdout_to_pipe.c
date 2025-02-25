/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdout_to_pipe.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:12:56 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/17 17:07:47 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// redirects STDOUT to the write end of a pipe
// returns the read end fd of that pipe (needs closing)
// returns -1 if error
int	ft_stdout_to_pipe(void)
{
	int	pipe_one[2];

	if (pipe(pipe_one) == -1)
	{
		perror("Error creating pipe\n");
		return (-1);
	}
	if (dup2(pipe_one[1], STDOUT_FILENO) < 0)
	{
		write(1, "\nSOP\n", 5);
		perror("Error redirecting stdout to write end of pipe\n");
		close(pipe_one[0]);
		close(pipe_one[1]);
		return (-1);
	}
	close(pipe_one[1]);
	return (pipe_one[0]);
}
