/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_input_loop.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 18:30:46 by sikunne           #+#    #+#             */
/*   Updated: 2025/04/01 19:16:01 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Redirects stdin and stdout according to pipes in tokens
// Expects *fd to be r_end of last pipe
// Reassigns *fd if new pipe needed or sets it to -1 if not
// If not at start, make a pipe and set to stdin
// If current chunk does not end in NULL, make a pipe and set to stdout
// As well as returning that pipes r_end fd through <*fd>
// Returns 0 if all nominal, continue
// Returns -1 if error, stop current line
static int	st_pipes(t_shell *shl, int pos, int *fd)
{
	int	status;

	status = 0;
	if (pos != 0)
		status = ft_stdin_to_pipe(fd);
	if (status != 0)
	{
		shl->exit_code = 1;
		return (1);
	}
	while (ft_is_delimiter(shl->tok[pos]) == 0)
		pos++;
	if (ft_b_strcmp(shl->tok[pos], "|") != 0)
	{
		*fd = -1;
		return (0);
	}
	*fd = ft_stdout_to_pipe();
	if (*fd == -1)
	{
		shl->exit_code = 1;
		return (1);
	}
	return (0);
}

// Runs for each chunk
// reset std fds, check if current chunk takes pipe input,
// then checks if new pipe needs to be made for current chunk
// then handles contents of chunk
int	ft_handle_input_loop(t_shell *shl, int *std)
{
	int	last_pipe;
	int	status;
	int	i;

	last_pipe = -1;
	status = 0;
	i = 0;
	while (shl->tok[i] != NULL)
	{
		ft_std_reset(std);
		status = st_pipes(shl, i, &last_pipe);
		if (status != 0)
			break ;
		status = ft_handle_chunks(shl, &i);
		if (status != 0)
			break ;
		if (shl->tok[i] != NULL)
			i++;
	}
	ft_b_close(&last_pipe);
	return (status);
}
