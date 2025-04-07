/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc_prepare.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 18:06:34 by sikunne           #+#    #+#             */
/*   Updated: 2025/04/07 20:48:48 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Ran for each Heredoc that needs to be initialized
// Gets input for heredoc and turns it into one long string
// Then substitutes Arguments in that string
// Then puts string into pipe and puts fd to shl->hd_fd array
// returns 0 if ended nominally
// returns 1 if Ctrl+c was called and line should be stopped
static int	st_get_heredoc_inp(t_shell *shl, char *stop, int pos)
{
	char	*new_buf;
	char	*total_buf;
	int		status;

	status = 0;
	total_buf = NULL;
	new_buf = readline("heredoc > ");
	status = ft_heredoc_sigs(shl, &new_buf, &total_buf);
	if (status != 0)
		return (status);
	if (ft_b_strcmp(new_buf, stop) == 0)
	{
		ft_null(&new_buf);
		ft_heredoc_str_to_lst(shl, NULL, pos);
		return (0);
	}
	while (ft_b_strcmp(new_buf, stop) != 0 && status == 0)
		status = ft_heredoc_string(shl, &new_buf, &total_buf);
	ft_subst_string(shl, &total_buf);
	ft_heredoc_str_to_lst(shl, total_buf, pos);
	ft_null(&total_buf);
	ft_null(&new_buf);
	return (status);
}

// Fills the Heredoc Array with content by calling a function for
// every << it encounters
// returns 0 if nominal or 1 or 2 based on signal
static int	st_fill_hd_array(t_shell *shl, int count)
{
	int	i;
	int	pos;
	int	status;

	i = -1;
	pos = 0;
	shl->hd_fd = (int *)malloc((count + 1) * sizeof(int));
	while (++i <= count)
		shl->hd_fd[i] = -2;
	i = -1;
	while (shl->tok[++i] != NULL)
	{
		if (ft_b_strcmp(shl->tok[i], "<<") != 0)
			continue ;
		if (ft_is_del_or_red(shl->tok[i + 1]) == 1)
		{
			ft_perror("yevshell: HEREDOC not given delimiter\n", NULL, NULL);
			return (1);
		}
		status = st_get_heredoc_inp(shl, shl->tok[i + 1], pos);
		pos++;
		if (status != 0)
			return (status);
	}
	return (0);
}

// Handles getting Heredoc Content
// puts it into pipes and stores the pipes r_end fd in shl->hd_fd
int	ft_heredoc_prepare(t_shell *shl)
{
	int	i;
	int	count;
	int	status;

	i = 0;
	shl->hd_fd = NULL;
	while (shl->tok[i] != NULL)
		i++;
	count = ft_count_prev_hds(shl, i);
	if (count == 0)
		return (0);
	status = st_fill_hd_array(shl, count);
	return (status);
}
