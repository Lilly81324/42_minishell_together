/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:43:25 by sikunne           #+#    #+#             */
/*   Updated: 2024/11/15 15:36:05 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

// returns a new string that is the sum of..
// ..s1 and s2. If one is NULL it still works..
// ..but if both are NULL it returns only NULL
char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		s1len;
	int		s2len;
	char	*result;

	i = -1;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	result = (char *)malloc((s1len + s2len + 1) * sizeof(char));
	if (result == NULL)
		return (result);
	while (i++ < s1len - 1)
		result[i] = s1[i];
	i = -1;
	while (i++ < s2len - 1)
		result[i + s1len] = s2[i];
	result[i + s1len] = '\0';
	return (result);
}

// int	main(void)
// {
// 	char	*s1;
// 	char	*s2;

// 	s1 = "alpha";
// 	s2 = NULL;
// 	printf("%s", ft_strjoin(s1, s2));
// 	return (0);
// }
