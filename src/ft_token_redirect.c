/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_redirect.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:24:50 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/26 15:58:46 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Called at index <i> of first element of block <arg>
// Moves through all elements, ignoring everything that is not a redirector
// Moves until it finds NULL or a block starting with '|' or ';'
// If it finds redirector then handle redirection to/from file in next token
// Then skip to the next next token, thereby skipping redirector and filename
// Handle_chunks return value scheme
int	ft_token_redirect(char *arg[], int i)
{
	int	status;

	while (ft_is_delimiter(arg[i]) == 0)
	{
		if (ft_is_redirector(arg[i]) == 1)
		{
			status = ft_redirection(arg, i);
			if (status != -1)
				return (status);
			i += 2;
		}
		else
			i++;
	}
	return (-1);
}

// CAn currently not handle pipes, even though the condition is there
// The read end of the pipe, being the return value of ft_stdout_to_pipe()
// will need to be set as stdin before the redirection step of the next chunk
// which might need its own value to be pares through functions
