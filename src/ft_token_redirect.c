/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_redirect.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:24:50 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/20 17:39:09 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Called at index <i> of first element of tokens <tok>
// Moves through all elements, ignoring everything that is not a redirector
// Moves until it finds NULL or a block starting with '|' or ';'
// If it finds redirector then handle redirection to/from file in next token
// Then skip to the next next token, thereby skipping redirector and filename
// Handle_chunks return value scheme
int	ft_token_redirect(t_shell *shl, int i)
{
	int	status;

	while (ft_is_delimiter(shl->tok[i]) == 0)
	{
		if (ft_is_redirector(shl->tok[i]) == 1)
		{
			status = ft_redirection(shl, i);
			if (status > 0)
				return (status);
			i += 2;
		}
		else
			i++;
	}
	return (0);
}
