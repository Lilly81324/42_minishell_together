/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:52:25 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/20 18:13:26 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// handles the whole input string 
// substitutes arguments, then breaks input into tokens
// Then calls a loop for every chunk of tokens
// Return value meaning: 
// 0 - continue running
// 1 - stop current chunk, move on to next
// 2 - stop programm
int	ft_handle_input(char **inp, t_shell *shl)
{
	int		status;
	int		std[3];

	ft_string_substitution(shl, inp);
	shl->tok = ft_tokenization(*inp);
	if (shl->tok == NULL)
	{
		ft_perror(NULL_INPUT, NULL, NULL);
		return (1);
	}
	// ft_print_tokens(tokens);
	ft_std_dup(std);
	ft_redirect_heredocs(shl);
	status = ft_handle_input_loop(shl, std);
	ft_std_reset(std);
	ft_std_close(std);
	ft_hdlst_clear(shl->start);
	ft_nullb(&shl->tok);
	return (status);
}
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
