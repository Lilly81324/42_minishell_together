/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect_heredocs.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 18:06:34 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/20 18:01:39 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// HEREDOCS should be handled here
// After tokenization make a special bit of code
// There we check how many HEREDOCS there are.
// If there is at least one, do the following
// Create a pipe
// For each one, left to right, use readline to get an input
// Save input into one long string, then substitute it (tokenize as well?)
// Save that updated string into the w_end, until input is exaclty delimiter
// Close the w_end, put the r_end into a linked list
// Repeat with new list entries for each HEREDOC
// Save list in shl
// Continue with normal programm execution, 
// anytime HEREODC as input is used, update heredoc_pos in shl
// Then use stdin_to_pipe for that chunk
// If error encountered and heredoc_pos isnt the last element,
// close the rest of the pipes that were unused
// Then, before back to loop, free linked list and set it in shl to NULL

// Puts <s> into pipe and adds read_end fd to linked list in shl

static void	st_string_to_lst(t_shell *shl, char *s)
{
	int	pipeline[2];

	if (pipe(pipeline) == -1)
	{
		ft_perror(REDIR_INVAL_PIPE, NULL, NULL);
		return ;
	}
	write(pipeline[1], s, (ft_strlen(s) * sizeof(char)));
	close(pipeline[1]);
	ft_hdlst_add(&(shl->start), pipeline[0]);
}

static void	st_get_heredoc_inp(t_shell *shl, int count)
{
	char	*new_buf;
	char	*temp;
	char	*total_buf;

	while (count > 0)
	{
		new_buf = NULL;
		total_buf = NULL;
		new_buf = readline("heredoc > ");
		while (ft_strncmp(new_buf, "EOF", 4) != 0)
		{
			temp = ft_strjoin(total_buf, new_buf);
			ft_null(&new_buf);
			ft_null(&total_buf);
			total_buf = temp;
			temp = ft_strjoin(total_buf, "\n");
			ft_null(&total_buf);
			total_buf = temp;
			new_buf = readline("heredoc > ");
		}
		ft_null(&new_buf);
		st_string_to_lst(shl, total_buf);
		ft_null(&total_buf);
		count--;
	}
}

// Called after input was tonized and subsitituted
// but before any commands run
void	ft_redirect_heredocs(t_shell *shl)
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
