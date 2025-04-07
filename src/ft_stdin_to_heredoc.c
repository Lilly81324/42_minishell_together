/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdin_to_heredoc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:28:00 by sikunne           #+#    #+#             */
/*   Updated: 2025/04/07 20:39:02 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// << EOF cat | << EOF cat | cat
int	ft_stdin_to_heredoc(t_shell *shl, int pos)
{
	int	count;

	count = ft_count_prev_hds(shl, pos) - 1;
	if (dup2(shl->hd_fd[count], STDIN_FILENO) < 0)
	{
		ft_b_close(&(shl->hd_fd[count]));
		return (1);
	}
	ft_b_close(&(shl->hd_fd[count]));
	return (0);
}
