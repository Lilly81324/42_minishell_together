/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multichunk.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:07:08 by sikunne           #+#    #+#             */
/*   Updated: 2025/04/03 18:22:44 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_multichunk(t_shell *shl, int *std, int *pos)
{
	int		i;
	int		status;
	int		last_pipe;
	int		pipe_count;
	char	***subenv;

	i = 0;
	status = 0;
	last_pipe = -1;
	pipe_count = ft_count_pipes(shl->tok, *pos);
	subenv = ft_env_subshell(shl->env, pipe_count + 1);
	while (ft_is_chunk_delim(shl->tok[*pos]) == 0)
	{// For each piped subchunk:
		ft_std_reset(std);
		status = ft_pipes(shl, *pos, &last_pipe);
		if (status != 0)
			break ;
		status = ft_subchunk(shl, pos, &(subenv[i]));
		if (status != 0)
			break ;
		if (shl->tok[*pos] != NULL)
			(*pos)++;
		i++;
	}
	ft_nulld(&subenv);
	ft_b_close(&last_pipe);
	return (status);
}
