/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subchunk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:38:35 by sikunne           #+#    #+#             */
/*   Updated: 2025/04/01 17:45:56 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Redirects stdin and stdout according to pipes in tokens
// Requires <from> to be r_end of last pipe (or -1 if not)
// Sets <*to> to -2 -> no pipe needed since at end, 
// Sets <*to> to -1 -> error, should stop line anyway
// Sets <*to> to value > 2 	-> read end of pipe for next command
// If not at start, make a pipe and set to stdin
// If current chunk does not end in NULL, make a pipe and set to stdout
// As well as returning that pipes r_end fd through <*to>
// Returns 0 if all nominal, continue
// Returns -1 if error, stop current line
static int	st_pipes(char **tok, int pos, int from, int *to)
{
	int	status;

	status = 0;
	if (pos != 0 && from != -1)
		status = ft_stdin_to_pipe(from);
	if (status != 0)
		return (status);
	while (ft_is_delimiter(tok[pos]) == 0)
		pos++;
	if (tok[pos] == NULL)
	{
		*to = -2;
		return (0);
	}
	*to = ft_stdout_to_pipe();
	if (*to == -1)
		return (-1);
	return (0);
}

int	ft_subchunk(char **tok, int pos, int pipe)
{
	int		w_end;
	char	**arg;

	w_end = -1;
	st_pipes(tok, pos, pipe, &w_end);
	return (0);
}
