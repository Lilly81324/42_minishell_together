/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:58:30 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/10 19:18:52 by sikunne          ###   ########.fr       */
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

// Retuns a newly ALLOCATED string that consists of 
// adding <goal> into <src> at position <pos>
// returns NULL if either string is NULL
// if position bigger than len of <src>, then insert at end (adding)
// alternatively set pos to -1 fo adding
char	*ft_str_insert(char *src, char *goal, int pos)
{
	int		i;
	int		j;
	char	*new;

	if (src == NULL || goal == NULL)
		return (NULL);
	if (pos < 0 || pos >= (int)st_get_len(src))
		pos = st_get_len(src);
	new = (char *)malloc((st_get_len(src) + st_get_len(goal) + 1) \
						* sizeof(char));
	if (new == NULL)
		return (NULL);
	i = -1;
	while (++i < pos)
		new[i] = src[i];
	j = -1;
	while (goal[++j] != '\0')
		new[i + j] = goal[j];
	i--;
	while (src[++i] != '\0')
		new[i + j] = src[i];
	new[i + j] = '\0';
	return (new);
}
