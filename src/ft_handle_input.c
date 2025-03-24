/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:52:25 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/24 17:04:58 by sikunne          ###   ########.fr       */
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
	ft_strip_tokens(shl->tok);
	// ft_print_tokens(shl->tok);
	ft_std_dup(std);
	status = ft_heredoc_prepare(shl);
	if (status == 0)
		status = ft_handle_input_loop(shl, std);
	ft_std_reset(std);
	ft_std_close(std);
	ft_hdlst_clear(shl->start);
	ft_nullb(&shl->tok);
	return (status);
}
