/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:52:25 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/12 16:52:56 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// return values: -1 for continue 0-255 for  
// certain return values should stop the programm and return that value
// -1 if continue
// 0-255 for stop the working with the line and free it
// 1000-1255 for stop whole programm
// handles a whole input string, breaks it down into chunks
// and then does all chunks in a specific order
int	ft_handle_input(char **inp, t_shell *shl)
{
	int		status;
	int		std[3];

	// printf("Test: %i\n", shl->exit_code);
	ft_string_substitution(shl, inp);
	shl->tok = ft_tokenization(*inp);
	if (shl->tok == NULL)
		return (1);
	// ft_print_tokens(tokens);
	ft_std_dup(std);
	status = ft_handle_input_loop(shl, std);
	ft_std_reset(std);
	ft_std_close(std);
	ft_nullb(&shl->tok);
	return (status);
}
