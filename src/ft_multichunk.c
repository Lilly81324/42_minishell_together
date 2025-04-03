/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multichunk.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:07:08 by sikunne           #+#    #+#             */
/*   Updated: 2025/04/03 16:43:14 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Execute this for every chunk
static int	st_placeholder(t_shell *shl, int pipepos, int *pos)
{
	int		status;

	status = ft_subchunk(shl, pos, env);
	printf("Returning status %i\n", status);
	return (status);
}

int	ft_multichunk(t_shell *shl, int *std, int *pos)
{
	int	i;
	int	status;
	int	last_pipe;
	int	pipe_count;

	i = 0;
	status = 0;
	last_pipe = -1;
	pipe_count = ft_count_pipes(shl->tok, *pos);
	shl->subenv = ft_make_subenv(shl, pipe_count);
	while (ft_is_delimiter(shl->tok[i]) == 0)
	{
		// For each piped subchunk:
		ft_std_reset(std);
		status = ft_pipes(shl, i, &last_pipe);
		if (status != 0)
			break ;
		status = st_placeholder(shl, i, *pos);
		if (status != 0)
			break ;
		if (shl->tok[i] != NULL)
			i++;
	}
	ft_b_close(&last_pipe);
	return (status);
}
