/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepare_argv.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:09:11 by sikunne           #+#    #+#             */
/*   Updated: 2025/04/04 16:51:26 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Prepares an array of char *by taking their addresses from the token list
// Theese individual entries should NOT be freed, since the tokens are nulled
// once the line is done. Instead only the pointer shoould be freed
// therefore we use ft_nullc on it to keep its contents but free their holder
static char	**ft_copy_argv(char **tok, int *pos, int len)
{
	char	**n_argv;
	int		i;

	n_argv = (char **)malloc((len + 2) * sizeof (char *));
	i = 0;
	while (ft_is_delimiter(tok[*pos]) == 0)
	{
		if (ft_is_redirector(tok[*pos]) == 1)
			ft_skip_redirector(tok, pos);
		else
		{
			n_argv[i] = tok[*pos];
			(*pos)++;
			i++;
		}
	}
	n_argv[i] = NULL;
	return (n_argv);
}

// creates a heap copy of the given string of arguments
// starting at arg[*start] and going until an argument is < > << >> or |
char	**ft_prepare_argv(char **tok, int *start)
{
	int		pos;
	int		len;
	char	**ret;

	pos = *start;
	len = 0;
	pos++;
	while (ft_is_delimiter(tok[pos]) == 0)
	{
		if (ft_is_redirector(tok[pos]) == 1)
			ft_skip_redirector(tok, &pos);
		else
		{
			pos++;
			len++;
		}
	}
	ret = ft_copy_argv(tok, start, len);
	return (ret);
}
