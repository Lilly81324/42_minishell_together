/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc_prepare.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 18:06:34 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/20 19:07:38 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Puts <s> into pipe and adds read_end fd to linked list in shl
// For a NULL string puts fd in linked lsit to -1
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
static void	st_add_to_heredoc(char **new_buf, char **total_buf)
{
	char	*temp;

	temp = ft_strjoin(*total_buf, *new_buf);
	ft_null(new_buf);
	ft_null(total_buf);
	*total_buf = temp;
	temp = ft_strjoin(*total_buf, "\n");
	ft_null(total_buf);
	*total_buf = temp;
	*new_buf = readline("heredoc > ");
}

// Runs for <count> amount of times, getting an input until EOF
// is inputted, puts input into pipe and marks pipes fd for later
static void	st_get_heredoc_inp(t_shell *shl, int count)
{
	char	*new_buf;
	char	*total_buf;

	while (count > 0)
	{
		new_buf = NULL;
		total_buf = NULL;
		new_buf = readline("heredoc > ");
		printf("Input: [%s]\n", new_buf);
		if (ft_strncmp(new_buf, "EOF", 4) == 0)
		{
			printf("Edge Case: Immideate EOF");
			ft_null(&new_buf);
			st_string_to_lst(shl, NULL);
			count--;
		}
		while (ft_strncmp(new_buf, "EOF", 4) != 0)
			st_add_to_heredoc(&new_buf, &total_buf);
		ft_null(&new_buf);
		ft_string_substitution(shl, &total_buf);
		st_string_to_lst(shl, total_buf);
		ft_null(&total_buf);
		count--;
	}
}

// Called after input was tokenized and subsitituted
// but before any commands run
// gets the input for the heredocs into pipes for later
void	ft_heredoc_prepare(t_shell *shl)
{
	int		i;
	int		count;

	i = -1;
	shl->start = NULL;
	count = 0;
	while (shl->tok[++i] != NULL)
	{
		if (ft_strncmp(shl->tok[i], "<<", 3) == 0)
			count++;
	}
	if (count == 0)
		return ;
	st_get_heredoc_inp(shl, count);
}
