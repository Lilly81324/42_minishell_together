/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 09:06:17 by sikunne           #+#    #+#             */
/*   Updated: 2024/11/15 12:48:27 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static unsigned int	ft_st_strlen(const char *str)
{
	unsigned int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

// simply returns an empty character pointer or NULL if failed
static char	*ft_st_mptystrng(void)
{
	char	*result;

	result = (char *)malloc(1 * sizeof(char));
	if (result == NULL)
		return (NULL);
	result[0] = '\0';
	return (result);
}

// copies at most "len" characters or less.. 
// ..if it finds a '\0' and terminates the result
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;	
	size_t	strlen;
	char	*little;

	i = 0;
	if (s == NULL)
		return (NULL);
	strlen = ft_st_strlen(s);
	if (start >= strlen || len == 0)
		return (ft_st_mptystrng());
	if (len > strlen - start)
		len = strlen - start;
	little = (char *)malloc((len + 1) * sizeof(char));
	if (little == NULL)
		return (NULL);
	while (i < len)
	{
		little[i] = s[i + start];
		i++;
	}
	little[i] = '\0';
	return (little);
}
