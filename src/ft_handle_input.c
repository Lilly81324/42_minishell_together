/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:52:25 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/25 19:00:36 by sikunne          ###   ########.fr       */
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

	if (ft_sig_term(*inp) == 1)
		return (2);
	ft_string_substitution(shl, inp);
	shl->tok = ft_tokenization(*inp);
	ft_strip_tokens(shl->tok);
	if (shl->tok == NULL)
		return (1);
	// ft_print_tokens(shl->tok);
	ft_std_dup(std);
	status = ft_heredoc_prepare(shl);
	signal(SIGINT, ft_sig_int);
	if (status == 0)
		status = ft_handle_input_loop(shl, std);
	ft_std_reset(std);
	ft_std_close(std);
	ft_hdlst_clear(shl->start);
	ft_nullb(&shl->tok);
	return (status);
}
