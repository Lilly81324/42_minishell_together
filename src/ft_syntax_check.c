/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syntax_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:38:18 by sikunne           #+#    #+#             */
/*   Updated: 2025/04/08 18:31:31 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// checks if redirector is followed by non redirector or non delimiter
// returns 0 if yes
// returns 1 if no, at any point
static int	st_redir_check(char **tok)
{
	int	i;

	i = -1;
	while (tok[++i] != NULL)
	{
		if (ft_is_redirector(tok[i]) == 1 && \
			ft_is_del_or_red(tok[i + 1]) == 1)
		{
			ft_perror(SYNTAX_REDIR, tok[i], NULL);
			return (1);
		}
	}
	return (0);
}

// checks if pipe is followed by not NULL or not other pipe
// returns 0 if yes (valid token after)
// returns 1 if no, at any point
static int	st_pipe_check(char **tok)
{
	int	i;

	i = -1;
	while (tok[++i] != NULL)
	{
		if (ft_b_strcmp(tok[i], "|") == 0 && \
			tok[i + 1] == NULL)
		{
			ft_perror(SYNTAX_REDIR, tok[i], NULL);
			return (1);
		}
		else if (ft_b_strcmp(tok[i], "|") == 0 && \
			ft_b_strcmp(tok[i + 1], "|") == 0)
		{
			ft_perror(SYNTAX_REDIR, tok[i], NULL);
			return (1);
		}
	}
	return (0);
}

// returns 1 if syntax invalid, also perrors
// no file after redirector -> no execution
// empty command before pipe "| echo hello" -> no exectuion
// empty commands between two pipes -> no execution
// pipe as last token -> no execution <-- CONTROVERSIAL
int	ft_syntax_check(t_shell *shl)
{
	int	status;

	status = 0;
	if (shl->tok[0] == NULL)
		return (0);
	if (ft_b_strcmp(shl->tok[0], "|") == 0)
	{
		ft_perror(SYNTAX_REDIR, shl->tok[0], NULL);
		status = 1;
	}
	if (status == 0)
		status = st_redir_check(shl->tok);
	if (status == 0)
		status = st_pipe_check(shl->tok);
	shl->exit_code = ERNUM_SYNTAX;
	return (status);
}
