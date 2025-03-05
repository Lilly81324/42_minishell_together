/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_input_loop.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 18:30:46 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/05 18:01:49 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Runs for each chunk
// reset std fds, check if current chunk takes pipe input,
// then checks if new pipe needs to be made for current chunk
// then handles contents of chunk
int	ft_handle_input_loop(char **tokens, int *std, char ***envp)
{
	int	r_end;
	int	status;
	int	i;

	r_end = -1;
	status = -1;
	i = 0;
	while (tokens[i] != NULL && status == -1)
	{
		ft_std_reset(std);
		if (r_end != -1)
			ft_stdin_to_pipe(r_end);
		r_end = ft_pipe_setup(tokens, i);
		status = ft_handle_chunks(tokens, &i, envp);
		if (tokens[i] != NULL)
			i++;
	}
	return (status);
}
