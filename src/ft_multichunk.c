/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multichunk.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:07:08 by sikunne           #+#    #+#             */
/*   Updated: 2025/04/04 15:28:34 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	st_wait(t_shell *shl, int childcount, pid_t last_pid)
{
	int		i;
	int		status;
	pid_t	died;

	i = -1;
	while (++i < childcount)
	{
		died = waitpid(-1, &status, 0);
		if (died == last_pid)
			shl->exit_code = WEXITSTATUS(status);
	}
}

int	ft_multichunk(t_shell *shl, int *std, int *pos)
{
	int		i;
	pid_t	pid;
	int		last_pipe;
	int		pipe_count;

	i = 0;
	last_pipe = -1;
	pipe_count = ft_count_pipes(shl->tok, *pos);
	while (ft_is_chunk_delim(shl->tok[*pos]) == 0)
	{
		ft_std_reset(std);
		if (ft_pipes(shl, *pos, &last_pipe) != 0)
			break ;
		shl->subenv = ft_env_subshell(shl->env);
		pid = ft_subchunk(shl, pos, std, last_pipe);
		ft_nullb(&shl->subenv);
		if (shl->tok[*pos] != NULL)
			(*pos)++;
		i++;
	}
	if (i == pipe_count + 1)
		st_wait(shl, pipe_count + 1, pid);
	ft_b_close(&last_pipe);
	return (0);
}
