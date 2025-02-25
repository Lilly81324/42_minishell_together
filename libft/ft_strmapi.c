/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:59:34 by sikunne           #+#    #+#             */
/*   Updated: 2024/11/14 17:47:46 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

//creates and returns a copy of a given string
static char	*ft_st_strcpy(char const *src)
{
	int		i;
	int		srclen;
	char	*dest;

	i = 0;
	srclen = 0;
	while (src[srclen] != '\0')
		srclen++;
	dest = (char *)malloc(((srclen) + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

// takes a string s und does fucntion f on it
// function f uses unsigned ints and characters
// returns a string
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*res;

	i = 0;
	if (s == NULL)
		return (NULL);
	res = ft_st_strcpy(s);
	if (res == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		res[i] = (*f)(i, s[i]);
		i++;
	}
	return (res);
}
