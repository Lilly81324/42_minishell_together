/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc_prepare.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 18:06:34 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/28 17:19:45 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Ran for each Heredoc that needs to be initialized
// Gets input for heredoc and turns it into one long string
// Then substitutes Arguments in that string
// Then puts string into pipe and adds a node in shl->start
// returns 0 if ended nominally
// returns 1 if Ctrl+c was called and line should be stopped
static int	st_get_heredoc_inp(t_shell *shl, char *stop)
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
		ft_heredoc_str_to_lst(shl, NULL);
		return (0);
	}
	while (ft_b_strcmp(new_buf, stop) != 0 && status == 0)
		status = ft_heredoc_string(shl, &new_buf, &total_buf);
	ft_subst_string(shl, &total_buf);
	ft_heredoc_str_to_lst(shl, total_buf);
	ft_null(&total_buf);
	ft_null(&new_buf);
	return (status);
}

// Called after input was tokenized and subsitituted
// but before any commands run
// gets the input for the heredocs into pipes for later
int	ft_heredoc_prepare(t_shell *shl)
{
	int		i;
	int		status;

	i = -1;
	shl->start = NULL;
	status = 0;
	while (shl->tok[++i] != NULL)
	{
		if (ft_b_strcmp(shl->tok[i], "<<") != 0)
			continue ;
		if (ft_is_del_or_red(shl->tok[i + 1]) == 1)
		{
			ft_perror("yevshell: HEREDOC not given delimiter\n", NULL, NULL);
			return (1);
		}
		status = st_get_heredoc_inp(shl, shl->tok[i + 1]);
		if (status != 0)
			return (status);
	}
	return (0);
}
