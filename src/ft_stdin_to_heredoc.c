/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdin_to_heredoc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:28:00 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/20 18:55:54 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	st_index_linked_list(t_shell *shl)
{
	int		i;
	t_lst	*node;

	i = -1;
	node = shl->start;
	while (++i < shl->heredoc_pos)
	{
		if (node == NULL)
			return (-1);
		node = node->next;
	}
	return (node->data);
}

int	ft_stdin_to_heredoc(t_shell *shl)
{
	int	r_end;
	int	i;

	i = 0;
	r_end = st_index_linked_list(shl);
	if (r_end == -2)
	{
		ft_perror(HERDOC_DIV, NULL, NULL);
		return (1);
	}
	if (dup2(r_end, STDIN_FILENO) < 0)
	{
		ft_perror(REDIR_PIPE_TO_INP, NULL, NULL);
		close(r_end);
		return (1);
	}
	shl->heredoc_pos++;
	close(r_end);
	return (0);
}
