/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subchunk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:38:35 by sikunne           #+#    #+#             */
/*   Updated: 2025/04/02 23:21:42 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Old:
// Input is given
// SIGINT check
// Added to history
// SIGEOF check
// Tokenized (Substitution, Tokenization, Stripping)
// STD fds copied
// HEREDOCs prepared
// [
// STD fds reset
// pipe redirection
// redir redirection
// commands run
// move to end of chunk
// return status code
// ]
// close last pipe
// reset STD
// close STD
// clear HEREDOCs
// check return status

// New:
// Input is given
// SIGINT check
// Added to history
// SIGEOF check
// Tokenized (Substitution, Tokenization, Stripping)
// STD fds copied
// HEREDOCs prepared
// [
// redir redirection
// command run
// set exit code
// return status
// ]
// [
// STD fds reset
// pipe redirection
// redir redirection
// commands run
// move to end of chunk
// "return" exit code
// after loop set exit code to last commands exit code
// ]
// close last pipe
// reset STD
// close STD
// clear HEREDOCs
// check return status
int	ft_subchunk(t_shell *shl, int *pos, char ***envp)
{
	int	status;

	status = ft_token_redirect(shl, *pos);
	if (status > 0)
		return (status);
	status = ft_token_cmds(shl, *pos);
	if (status > 0)
		return (status);
	while (ft_is_delimiter(shl->tok[*pos]) != 1)
		(*pos)++;
	return (0);
}

