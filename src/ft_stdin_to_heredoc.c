/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdin_to_heredoc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:28:00 by sikunne           #+#    #+#             */
/*   Updated: 2025/04/02 23:14:36 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_lst	*st_index_linked_list(t_shell *shl)
{
	int		i;
	t_lst	*node;

	i = -1;
	node = shl->start;
	while (++i < shl->heredoc_pos)
	{
		if (node == NULL)
			return (NULL);
		node = node->next;
	}
	return (node);
}

int	ft_stdin_to_heredoc(t_shell *shl)
{
	t_lst	*node;

	node = st_index_linked_list(shl);
	if (node == NULL)
		return (0);
	if (dup2(node->data, STDIN_FILENO) < 0)
	{
		ft_perror(REDIR_PIPE_TO_INP, NULL, NULL);
		close(node->data);
		node->data = -1;
		return (1);
	}
	shl->heredoc_pos++;
	close(node->data);
	node->data = -1;
	return (0);
}
