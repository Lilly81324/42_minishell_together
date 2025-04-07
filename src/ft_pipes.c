/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 18:01:18 by sikunne           #+#    #+#             */
/*   Updated: 2025/04/03 17:41:53 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// The most convoluted function
// Redirects stdin and stdout according to pipes in tokens
// Expects *fd to be r_end of last pipe
// Reassigns *fd if new pipe needed or sets it to -1 if not
// If not at start, make a pipe and set to stdin
// If current chunk does not end in NULL, make a pipe and set to stdout
// As well as returning that pipes r_end fd through <*fd>
// Returns 0 if all nominal, continue
// Returns -1 if error, stop current line
int	ft_pipes(t_shell *shl, int pos, int *fd)
{
	int	status;

	status = 0;
	if (pos != 0)
		status = ft_stdin_to_pipe(*fd);
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
