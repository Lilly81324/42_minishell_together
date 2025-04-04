/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subchunk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:38:35 by sikunne           #+#    #+#             */
/*   Updated: 2025/04/04 14:15:59 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	st_subchunk_cleanup(t_shell *shl, int *std, int lpipe, char ***env)
{
	clear_history();
	ft_hdlst_clear(shl->start);
	ft_nullb(shl->env);
	ft_nullb(&shl->tok);
	ft_std_close(std);
	close(0);
	close(1);
	close(2);
	ft_b_close(&lpipe);
	ft_nullb(env);
}

int	ft_subchunk(t_shell *shl, int *pos, char **env, int *std, int lpipe)
{
	int		status;
	pid_t	pid;
	int		ex;

	ex = 0;
	pid = fork();
	if (pid == 0)
	{
		status = ft_token_redirect(shl, *pos);
		if (status == 0)
			status = ft_token_cmds(shl, *pos, &(env), &ex);
		st_subchunk_cleanup(shl, std, lpipe, &env);
		exit (status);
	}
	while (ft_is_delimiter(shl->tok[*pos]) != 1)
		(*pos)++;
	return (pid);
}

