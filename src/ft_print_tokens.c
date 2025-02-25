/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tokens.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:41:10 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/24 17:23:13 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// prints all the contents of the char arr arr
// usefull for seeing how the input was tokenizedr
void	ft_print_tokens(char **tokens)
{
	int	i;

	i = -1;
	while (tokens[++i] != NULL)
		printf("{%s}\n", tokens[i]);
}
