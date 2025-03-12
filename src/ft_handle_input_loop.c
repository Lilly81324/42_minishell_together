/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_input_loop.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 18:30:46 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/12 16:33:53 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Runs for each chunk
// reset std fds, check if current chunk takes pipe input,
// then checks if new pipe needs to be made for current chunk
// then handles contents of chunk
int	ft_handle_input_loop(t_shell *shl, int *std)
{
	int	r_end;
	int	status;
	int	i;

	r_end = -1;
	status = -1;
	i = 0;
	while (shl->tok[i] != NULL && status == -1)
	{
		ft_std_reset(std);
		if (r_end != -1)
			ft_stdin_to_pipe(r_end);
		r_end = ft_pipe_setup(shl->tok, i);
		status = ft_handle_chunks(shl, &i);
		printf("New Exit code: %i\n", status);
		shl->exit_code = status;
		if (shl->tok[i] != NULL)
			i++;
		if (status != -1)
			return (status);
	}
	return (status);
}
