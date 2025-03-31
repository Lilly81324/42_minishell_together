/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc_sigs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:09:48 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/28 18:32:06 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	st_heredoc_sigint_check(t_shell *shl)
{
	if (g_sig != SIGINT)
		return (0);
	shl->exit_code = ERNUM_CTRLC;
	g_sig = 0;
	return (1);
}

// Signal Handling for Ctrl+C SIGINT
// Returns 1 if Ctrl+C SIGINT was sent
// sets sets exit code and frees the given strings

int	ft_heredoc_sigs(t_shell *shl, char **n_buf, char **t_buf)
{
	int	status;

	status = 0;
	if (st_heredoc_sigint_check(shl) != 0)
		status = 1;
	else if (ft_sig_term(*n_buf) != 0)
		status = 2;
	else
		status = 0;
	if (status != 0)
	{
		ft_null(n_buf);
		ft_null(t_buf);
	}
	return (status);
}
