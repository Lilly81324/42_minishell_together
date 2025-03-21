/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc_prepare.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 18:06:34 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/21 19:00:54 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Returns 2 if Ctrl+C SIGINT was sent
// sets sets exit code and frees the given strings
static int	st_sig_check(t_shell *shl, char **n_buf, char **t_buf)
{
	if (g_signal == SIGINT)
	{
		printf("CTRL+C received in heredoc!!!\n");
		ft_null(n_buf);
		ft_null(t_buf);
		g_signal = 0;
		shl->exit_code = ERNUM_HRDOC_CTRLC;
		return (1);
	}
	return (0);
}

// Puts <s> into pipe and adds read_end fd to linked list in shl
// For a NULL string puts nothing into pipe
// which later gets interpreted as empty input
static void	st_string_to_lst(t_shell *shl, char *s)
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

// Adds the <*new_buf> to the current <*total_buf> by reallocating
// as well as adding a newline after it
// Then uses readline to get another new_buf for the next call
// returns 1 if Ctrl+C was called or 0 if not
static int	st_add_to_heredoc(t_shell *shl, char **new_buf, char **total_buf)
{
	char	*temp;

	if (st_sig_check(shl, new_buf, total_buf) == 1)
		return (1);
	temp = ft_strjoin(*total_buf, *new_buf);
	ft_null(new_buf);
	ft_null(total_buf);
	*total_buf = temp;
	temp = ft_strjoin(*total_buf, "\n");
	ft_null(total_buf);
	*total_buf = temp;
	*new_buf = readline("heredoc > ");
	return (0);
}

// Runs for <count> amount of times, getting an input until EOF
// is inputted, puts input into pipe and marks pipes fd for later
static int	st_get_heredoc_inp(t_shell *shl, int count)
{
	char	*new_buf;
	char	*total_buf;
	int		status;

	count++;
	status = 0;
	while (--count > 0)
	{
		new_buf = NULL;
		total_buf = NULL;
		new_buf = readline("heredoc > ");
		if (ft_b_strcmp(new_buf, "EOF") == 0)
		{
			ft_null(&new_buf);
			st_string_to_lst(shl, NULL);
			continue ;
		}
		while (ft_b_strcmp(new_buf, "EOF") != 0 && status == 0)
			status = st_add_to_heredoc(shl, &new_buf, &total_buf);
		ft_string_substitution(shl, &total_buf);
		st_string_to_lst(shl, total_buf);
		ft_null(&total_buf);
		ft_null(&new_buf);
	}
	return (0);
}

// Called after input was tokenized and subsitituted
// but before any commands run
// gets the input for the heredocs into pipes for later
int	ft_heredoc_prepare(t_shell *shl)
{
	int		i;
	int		count;

	i = -1;
	shl->start = NULL;
	count = 0;
	while (shl->tok[++i] != NULL)
	{
		if (ft_b_strcmp(shl->tok[i], "<<") == 0)
			count++;
	}
	if (count == 0)
		return (0);
	return (st_get_heredoc_inp(shl, count));
}
