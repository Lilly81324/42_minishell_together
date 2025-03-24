/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strip_tokens.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:47:58 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/24 17:04:38 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Removes pairs of quotes from string
// removes quotes from current position and their closer
// unless quotes arent closed
// move to next char, then move until next closer or end
// If at closer, cut that out, and cut the original quote
static void	st_strip_string(char **str)
{
	int	i;
	int	start;

	i = -1;
	while ((*str)[++i] != '\0')
	{
		if ((*str)[i] == '\"' || (*str)[i] == '\'')
		{
			start = i;
			i++;
			while ((*str)[i] != (*str)[start] && (*str)[i] != '\0')
				i++;
			if ((*str)[i] == '\0')
				return ;
			ft_str_cut(str, start, 1);
			i--;
			ft_str_cut(str, i, 1);
			i--;
		}
	}
}

// Removes pairs of quotes from every token
// "abc"		-> abc
// "'abc'def"	-> 'abc'def
void	ft_strip_tokens(char **tok)
{
	int	i;

	i = -1;
	while (tok[++i] != NULL)
		st_strip_string(&(tok[i]));
}
