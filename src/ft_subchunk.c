/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subchunk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:38:35 by sikunne           #+#    #+#             */
/*   Updated: 2025/04/07 20:40:42 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	st_subchunk_cleanup(t_shell *shl, char ***env)
{
	clear_history();
	ft_null_int(&shl->hd_fd);
	ft_nullb(shl->env);
	ft_nullb(&shl->tok);
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
	ft_nullb(env);
}

int	ft_subchunk(t_shell *shl, int *pos, int *std, int lpipe)
{
	int		status;
	pid_t	pid;
	int		ex;

	ex = 0;
	pid = fork();
	if (pid == 0)
	{
		ft_b_close(&lpipe);
		ft_std_close(std);
		status = ft_token_redirect(shl, *pos);
		if (status == 0)
			status = ft_token_cmds(shl, *pos, &(shl->subenv), &ex);
		st_subchunk_cleanup(shl, &(shl->subenv));
		exit (status);
	}
	while (ft_is_delimiter(shl->tok[*pos]) != 1)
		(*pos)++;
	return (pid);
}
