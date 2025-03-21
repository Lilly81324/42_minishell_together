/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_b_strcmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:23:17 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/21 17:07:13 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	st_strlen(char *str)
{
	int	len;

	len = 0;
	if (str == NULL)
		return (0);
	while (str[len] != '\0')
		len++;
	return (len);
}

// "better strcmp" Compares <s1> and <s2> and returns the difference
// of the first diverging char (s1[x] - s2[x])
// NOW checks for longer strlen, so no <n> neccesary
// NOW checks for NULL strings
// 2 NULLs give 0, otherwise they are treated like empty strings
int	ft_b_strcmp(char *s1, char *s2)
{
	int	s1len;
	int	s2len;

	if (s1 == NULL && s2 == NULL)
		return (0);
	if (s1 == NULL)
		return (((int)(s2[0])) * -1);
	if (s2 == NULL)
		return ((int)(s1[0]));
	s1len = st_strlen(s1);
	s2len = st_strlen(s2);
	if (s1len > s2len)
		return (ft_strncmp(s1, s2, s1len));
	else
		return (ft_strncmp(s1, s2, s2len));
}
