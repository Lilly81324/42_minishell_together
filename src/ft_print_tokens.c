/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tokens.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:41:10 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/27 17:43:13 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// prints all the contents of the char arr arr
// usefull for seeing how the input was tokenizedr
void	ft_print_tokens(char **tokens)
{
	int	i;

	i = -1;
	if (tokens == NULL)
	{
		ft_write_string("NULL Tokens\n");
		return ;
	}
	if (*tokens == NULL)
	{
		ft_write_string("Empty Tokens\n");
		return ;
	}
	while (tokens[++i] != NULL)
	{
		ft_write_string("{");
		ft_write_string(tokens[i]);
		ft_write_string("]\n");
	}
}
