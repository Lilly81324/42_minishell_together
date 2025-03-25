/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc_str_to_lst.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:45:08 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/25 18:45:51 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Puts <s> into pipe and adds read_end fd to linked list in shl
// For a NULL string puts nothing into pipe
// which later gets interpreted as empty input
void	ft_heredoc_str_to_lst(t_shell *shl, char *s)
{
	int	pipeline[2];

	if (pipe(pipeline) == -1)
	{
		ft_perror(REDIR_INVAL_PIPE, NULL, NULL);
		return ;
	}
	if (s != NULL)
		write(pipeline[1], s, (ft_strlen(s) * sizeof(char)));
	close(pipeline[1]);
	ft_hdlst_add(&(shl->start), pipeline[0]);
}
