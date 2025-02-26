/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_chunks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:48:42 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/26 16:02:22 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// called at start of chunk on first token
// first runs redirection for all tokens
// then runs commands for all tokens
// then skips to end of chunk
// return values:
// -1 for continue doing the line
// 0-255 for stop the current the line
// 1000-1255 for stop whole programm
int	ft_handle_chunks(char *arg[], int *i, char ***envp)
{
	int	status;

	status = ft_token_redirect(arg, *i);
	if (status > -1)
		return (status);
	status = ft_token_cmds(arg, *i, envp);
	if (status > -1)
		return (status);
	ft_token_skip_chunk(arg, i);
	return (-1);
}
