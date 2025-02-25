/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 10:27:07 by sikunne           #+#    #+#             */
/*   Updated: 2024/11/15 15:47:35 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

// returns a new copy of the given string s
char	*ft_strdup(const char *s)
{
	int		len;
	char	*ptr;

	len = 0;
	while (s[len] != '\0')
		len++;
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	len = 0;
	while (s[len] != '\0')
	{
		ptr[len] = s[len];
		len++;
	}
	ptr[len] = '\0';
	return (ptr);
}
