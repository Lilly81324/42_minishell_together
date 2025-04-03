/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multichunk.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:07:08 by sikunne           #+#    #+#             */
/*   Updated: 2025/04/03 16:07:34 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Execute this for every chunk
static int	st_placeholder(t_shell *shl, int *pos, char ***env)
{
	int		status;

	status = ft_subchunk(shl, pos, env);
	printf("Returning status %i\n", status);
	return (status);
}

int	ft_multichunk(t_shell *shl, int *std, int *pos)
{
	int			i;
	int			status;
	int			last_pipe;

	// For all piped chunks
	i = 0;
	status = 0;
	last_pipe = -1;
	while (ft_is_delimiter(shl->tok[i]) == 0)
	{
		// For each piped chunk:
		ft_std_reset(std);
		status = ft_pipes(shl, i, &last_pipe);
		if (status != 0)
			break ;
		status = st_placeholder(shl, &i);
		if (status != 0)
			break ;
		if (shl->tok[i] != NULL)
			i++;
	}
	ft_b_close(&last_pipe);
	return (status);
}
