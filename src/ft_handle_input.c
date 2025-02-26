/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:52:25 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/26 16:11:47 by sikunne          ###   ########.fr       */
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
	int		i;
	int		status;
	int		std[3];
	int		r_end;

	r_end = -1;
	tokens = ft_tokenization(inp);
	if (tokens == NULL)
		return (1);
	ft_print_tokens(tokens);
	i = 0;
	status = -1;
	ft_dup_std(std);
	while (tokens[i] != NULL && status == -1)
	{
		ft_reset_std(std);
		if (r_end != -1)
			ft_stdin_to_pipe(r_end);
		r_end = ft_pipe_setup(tokens, i);
		status = ft_handle_chunks(tokens, &i, envp);
		if (tokens[i] != NULL)
			i++;
	}
	ft_reset_std(std);
	ft_nullb(tokens);
	return (status);
}

// sets up tokenization of input
// makes copy of fds from before the commands
// then repeats: reset fds, check if current chunk takes pipe input,
//				  then checks if new pipe needs to be made for current chunk
//					then handles contents of chunk
// after that resets file descriptors and returns exit status of chunk