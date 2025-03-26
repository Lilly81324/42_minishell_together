/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc_prepare.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 18:06:34 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/26 17:51:05 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Signal Handling for Ctrl+C SIGINT
// Returns 1 if Ctrl+C SIGINT was sent
// sets sets exit code and frees the given strings
// static int	st_sig_check(t_shell *shl, char **n_buf, char **t_buf)
// {
// 	if (g_signal == SIGINT)
// 	{
// 		ft_null(n_buf);
// 		ft_null(t_buf);
// 		g_signal = 0;
// 		shl->exit_code = ERNUM_HRDOC_CTRLC;
// 		return (1);
// 	}
// 	return (0);
// }

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
	if (ft_sig_term(new_buf) == 1)
		return (2);
	if (ft_b_strcmp(new_buf, stop) == 0)
	{
		ft_null(&new_buf);
		ft_heredoc_str_to_lst(shl, NULL);
		return (0);
	}
	while (ft_b_strcmp(new_buf, stop) != 0 && status == 0)
		status = ft_heredoc_string(&new_buf, &total_buf);
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
	signal(SIGINT, ft_sig_int_heredoc);
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
