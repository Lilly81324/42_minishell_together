/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:52:10 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/12 19:18:10 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// handles redirections and increases the position accordingly
int	ft_redirection(char **tok, int pos)
{
	int	status;

	status = 0;
	if (tok[pos][0] == '>' && tok[pos][1] == '\0')
		status = ft_stdout_to_outfile(tok[pos + 1]);
	else if (tok[pos][0] == '<' && tok[pos][1] == '\0')
		status = ft_stdin_to_infile(tok[pos + 1]);
	else if (tok[pos][0] == '>' && tok[pos][1] == '>' \
			&& tok[pos][2] == '\0')
		status = ft_stdout_to_outfile_append(tok[pos + 1]);
	return (status);
}
