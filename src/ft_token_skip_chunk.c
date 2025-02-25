/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_skip_chunk.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:32:14 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/17 16:35:39 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// increases the position of the current token
// to the index of the marker of the end of the current chunk
// "ls", "-l", "|", "cat", "-e"
// -> would set *i to 2
void	ft_token_skip_chunk(char *arg[], int *i)
{
	while (arg[*i] != NULL && arg[*i][0] != '|' && arg[*i][0] != ';')
		(*i)++;
}
