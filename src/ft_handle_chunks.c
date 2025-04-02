/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_chunks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 18:30:46 by sikunne           #+#    #+#             */
/*   Updated: 2025/04/02 16:12:29 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Runs for each chunk
// reset std fds, check if current chunk takes pipe input,
// then checks if new pipe needs to be made for current chunk
// then handles contents of chunk
int	ft_handle_chunks(t_shell *shl, int *std)
{
	if (ft_syntax_check(shl) != 0)
		return (0);
	if (ft_check_singlechunk(shl->tok) == 1)
		return (ft_singlechunk(shl));
	return (ft_multichunk(shl, std));
}
