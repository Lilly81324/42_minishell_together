/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect_heredocs.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 18:06:34 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/19 18:29:06 by sikunne          ###   ########.fr       */
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

// Called after input was tonized and subsitituted
// but before any commands run
void	ft_redirect_heredocs(t_shell *shl)
{
	int		i;
	int		count;
	char	*buf;

	i = -1;
	count = 0;
	while (shl->tok[++i] != NULL)
	{
		if (ft_strncmp(shl->tok[i], "<<", 3) == 0)
		{
			printf("HEREDOC marker found at token %i [%s]\n", i, shl->tok[i]);
			printf("End marker : %s\n", shl->tok[i + 1]);
			count++;
		}
	}
	while (count > 0)
	{
		buf = readline("heredoc > ");
		while (ft_strncmp(buf, "EOF", 4) != 0)
		{
			ft_null(&buf);
			buf = readline("heredoc > ");
		}
		ft_null(&buf);
		count--;
	}
}
