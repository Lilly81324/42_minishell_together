/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:56:06 by sikunne           #+#    #+#             */
/*   Updated: 2024/11/15 12:47:44 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

// gives out an unsigned int showing how long a given string is
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

// cuts out substring s based on start and len
static char	*ft_st_substr(char const *s, int start, int len)
{
	int		i;
	int		strlen;
	char	*little;

	i = 0;
	if (s == NULL)
		return (ft_st_mptystrng());
	strlen = ft_st_strlen(s);
	if (start >= strlen)
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

// gives out 1 if character is found in string and 0 if not
static int	ft_st_char_in_str(const char *big, char little)
{
	int	i;

	i = 0;
	while (big[i] != '\0')
	{
		if (big[i] == little)
			return (1);
		i++;
	}
	return (0);
}

// trims certain given characters from start and end of given string
char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		srclen;
	int		start;

	i = 0;
	srclen = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	srclen = ft_st_strlen(s1);
	if (set[0] == '\0')
		return (ft_st_substr(s1, 0, srclen));
	while (ft_st_char_in_str(set, s1[i]) == 1 && s1[i] != '\0')
		i++;
	start = i;
	i = srclen - 1;
	while (ft_st_char_in_str(set, s1[i]) == 1 && i >= 0)
		i--;
	return (ft_st_substr(s1, start, i - start + 1));
}

// #include <stdio.h>

// int	main(int argc, char *argv[0])
// {
// 	if (argc == 1)
// 		return (0);
// 	printf("%s", ft_strtrim(argv[1], argv[2]));
// 	return (0);
// }
