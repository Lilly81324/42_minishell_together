/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenization.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:40:45 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/03 18:49:44 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Takes a string and converts it into a 2d array of tokens
// Tokens start at something that isnt SPACES
// Tokens end at SPECIALS
// SPECIALS will be turned into their own tokens
// # define SPACES " \n\t\v\f\r"
// # define SPECIALS "><;|"
// So a "<in.txt \ncat -e >>out.txt" will be turned to
//  "<", "in.txt", "cat", "-e", ">>", "out.txt"
char	**ft_tokenization(char *s)
{
	int		count;
	char	**result;
	int		i;

	if (s == NULL)
		return (NULL);
	count = ft_token_count(s);
	if (count < 1)
		return (NULL);
	result = (char **)malloc((count + 1) * sizeof(char *));
	i = -1;
	while (++i < count)
		result[i] = NULL;
	ft_token_extractor(s, &result);
	return (result);
}
