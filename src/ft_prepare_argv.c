/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepare_argv.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:09:11 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/17 17:29:45 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Prepares an array of char *by taking their addresses from the token list
// Theese individual entries should NOT be freed, since the tokens are nulled
// once the line is done. Instead only the pointer shoould be freed
// therefore we use ft_nullc on it to keep its contents but free their holder
static char	**ft_copy_argv(char **o_argv, int start, int len)
{
	char	**n_argv;
	int		i;

	n_argv = (char **)malloc((len + 1) * sizeof (char *));
	i = -1;
	while (++i < len)
		n_argv[i] = o_argv[i + start];
	n_argv[i] = NULL;
	return (n_argv);
}

// creates a heap copy of the given string of arguments
// starting at arg[*pos] and going until an argument is < > << >> or |
char	**ft_prepare_argv(char **arg, int *pos)
{
	int		len;
	char	**ret;

	len = 0;
	while (ft_is_delimiter(arg[len + (*pos)]) == 0)
		len++;
	ret = ft_copy_argv(arg, *pos, len);
	return (ret);
}
