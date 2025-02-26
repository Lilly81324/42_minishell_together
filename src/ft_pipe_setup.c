/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_setup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:41:17 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/26 16:06:16 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// checks wether current block needs piping, by checking next delimiter
// returns -1 if no pipe needed or a positive fd if needed
// if piping is required for chunk, then redirect stdin to pipe 
// and give back r_end fd so next chunk can take it as input
int	ft_pipe_setup(char **tokens, int pos)
{
	while (ft_is_delimiter(tokens[pos]) == 0)
		pos++;
	if (tokens[pos] == NULL || tokens[pos][0] == ';')
		return (-1);
	return(ft_stdout_to_pipe());
}
