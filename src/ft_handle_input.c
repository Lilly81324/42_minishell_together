/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:52:25 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/05 18:44:32 by sikunne          ###   ########.fr       */
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
int	ft_handle_input(char *inp, char ***envp)
{
	char	**tokens;
	int		status;
	int		std[3];

	tokens = ft_tokenization(inp);
	if (tokens == NULL)
		return (1);
	// ft_print_tokens(tokens);
	ft_std_dup(std);
	status = ft_handle_input_loop(tokens, std, envp);
	ft_std_reset(std);
	ft_std_close(std);
	ft_nullb(&tokens);
	return (status);
}

// sets up tokenization of input
// makes copy of fds from before the commands
// then runs the loop for each chunk
// after that resets file descriptors and returns exit status of chunk