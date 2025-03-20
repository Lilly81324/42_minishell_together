/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_chunks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:48:42 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/20 17:49:52 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// called at start of chunk on first token
// first runs redirection for all tokens
// then runs commands for all tokens
// then skips to end of chunk
// Return value meaning: 
// 0 - continue running
// 1 - stop current chunk, move on to next
// 2 - stop programm
int	ft_handle_chunks(t_shell *shl, int *i)
{
	int	status;

	status = ft_token_redirect(shl, *i);
	if (status > 0)
		return (status);
	status = ft_token_cmds(shl, *i);
	if (status > 0)
		return (status);
	while (ft_is_delimiter(shl->tok[*i]) != 1)
		(*i)++;
	return (0);
}
