/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_input_loop.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 18:30:46 by sikunne           #+#    #+#             */
/*   Updated: 2025/04/04 15:15:50 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Runs for each chunk
// reset std fds, check if current chunk takes pipe input,
// then checks if new pipe needs to be made for current chunk
// then handles contents of chunk
int	ft_handle_input_loop(t_shell *shl, int *std)
{
	int	status;
	int	i;

	status = 0;
	i = 0;
	if (ft_syntax_check(shl) != 0)
		return (0);
	while (shl->tok[i] != NULL && status == 0)
	{
		ft_std_reset(std);
		if (ft_count_pipes(shl->tok, i) == 0)
			status = ft_singlechunk(shl, &i);
		else
			status = ft_multichunk(shl, std, &i);
		if (shl->tok[i] != NULL)
			i++;
		if (status > 0)
			return (status);
	}
	return (status);
}
