/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:52:10 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/24 15:02:50 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// handles redirections and increases the position accordingly
int	ft_redirection(t_shell *shl, int pos)
{
	int		status;
	char	**tok;

	status = 0;
	tok = shl->tok;
	if (ft_b_strcmp(tok[pos], ">"))
		status = ft_stdout_to_outfile(tok[pos + 1]);
	else if (ft_b_strcmp(tok[pos], "<"))
		status = ft_stdin_to_infile(tok[pos + 1]);
	else if (ft_b_strcmp(tok[pos], ">>"))
		status = ft_stdout_to_outfile_append(tok[pos + 1]);
	else if (ft_b_strcmp(tok[pos], "<<"))
		status = ft_stdin_to_heredoc(shl);
	return (status);
}
