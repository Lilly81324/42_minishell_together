/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdin_to_pipe.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:14:02 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/13 17:15:11 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// redirects STDIN to the read end of a pipe
// returns 0
// returns -1 if error
int	ft_stdin_to_pipe(int r_end)
{
	if (r_end == -1)
	{
		ft_perror(REDIR_INVAL_PIPE, NULL, NULL);
		return (-1);
	}
	if (dup2(r_end, STDIN_FILENO) < 0)
	{
		ft_perror(REDIR_PIPE_TO_INP, NULL, NULL);
		close(r_end);
		return (-1);
	}
	close(r_end);
	return (0);
}
