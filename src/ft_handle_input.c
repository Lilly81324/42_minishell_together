/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:52:25 by sikunne           #+#    #+#             */
/*   Updated: 2025/04/07 20:45:14 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Prepares the tokens and catches errors regarding tokens
// if Input is NULL then Ctrl+D was sent	-> return 2
// if Tokenization failed					-> return 1
// otherwise return 0 which continues programm
static int	st_tokenizer(t_shell *shl, char **inp)
{
	if (ft_sig_term(*inp) == 1)
		return (2);
	ft_subst_string(shl, inp);
	shl->tok = ft_tokenization(*inp);
	ft_strip_tokens(shl->tok);
	if (shl->tok == NULL)
	{
		shl->exit_code = 1;
		return (1);
	}
	return (0);
}

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

	status = st_tokenizer(shl, inp);
	ft_null(inp);
	if (status != 0)
		return (status);
	ft_std_dup(std);
	status = ft_heredoc_prepare(shl);
	if (status == 0)
		status = ft_handle_input_loop(shl, std);
	ft_std_reset(std);
	ft_std_close(std);
	ft_null_int(&shl->hd_fd);
	ft_nullb(&shl->tok);
	return (status);
}
