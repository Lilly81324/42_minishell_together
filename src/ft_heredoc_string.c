/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:37:23 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/28 17:20:45 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Adds the <*new_buf> to the current <*total_buf> by reallocating
// as well as adding a newline after it
// Then uses readline to get another new_buf for the next call
int	ft_heredoc_string(t_shell *shl, char **new_buf, char **total_buf)
{
	int		status;
	char	*temp;

	temp = ft_strjoin(*total_buf, *new_buf);
	ft_null(new_buf);
	ft_null(total_buf);
	*total_buf = temp;
	temp = ft_strjoin(*total_buf, "\n");
	ft_null(total_buf);
	*total_buf = temp;
	*new_buf = readline("heredoc > ");
	status = ft_heredoc_sigs(shl, new_buf, total_buf);
	return (status);
}
