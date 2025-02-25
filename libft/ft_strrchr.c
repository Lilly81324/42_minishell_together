/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:09:55 by sikunne           #+#    #+#             */
/*   Updated: 2024/11/15 16:02:01 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

// counts length of given string, then checks, starting at end..
// and going to index 0 and returns pointer to last occurence of c
// last means the first instance that it encounters
char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*dest;

	i = 0;
	dest = NULL;
	while (s[i] != '\0')
		i++;
	if ((char)c == '\0')
		return ((char *)(&s[i]));
	while (i > 0)
	{
		if (s[i] == (char)c)
		{
			dest = (char *)(&s[i]);
			return (dest);
		}
		i--;
	}
	if (s[0] == (char)c)
		dest = (char *)(&s[0]);
	return (dest);
}
