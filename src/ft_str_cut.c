/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_cut.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:42:24 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/10 19:09:45 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// returns len of chars in string
// without \0
// for NULL returns -1
static int	st_get_len(char *s1)
{
	int	len;

	len = 0;
	if (s1 == NULL)
		return (0);
	while (s1[len] != '\0')
		len++;
	return (len);
}

// Cuts characters out of string by reallocating the string
// Removes the <cutlen> characters starting at <pos> from string <*src>
// returns -1 if error (string NULL, pos out of bounds)
// returns 0 if nominal
// if <cutlen> bigger then length of <*src> cuts all after <pos> 
int	ft_str_cut(char **src, int pos, int cutlen)
{
	int		i;
	char	*new;

	if (*src == NULL)
		return (-1);
	if (pos >= st_get_len(*src))
		return (-1);
	if (pos + cutlen > st_get_len(*src))
		cutlen = st_get_len(*src) - pos;
	new = (char *)malloc((st_get_len(*src) - cutlen + 1) * sizeof(char));
	if (new == NULL)
		return (-1);
	i = -1;
	while (++i < pos)
		new[i] = (*src)[i];
	i--;
	while ((*src)[++i + cutlen] != '\0')
		new[i] = (*src)[i + cutlen];
	free(*src);
	*src = new;
	return (0);
}
