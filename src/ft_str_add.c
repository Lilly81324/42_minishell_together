/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:47:59 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/10 18:40:59 by sikunne          ###   ########.fr       */
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

// Adds string1 and 2 together and returns the result
// Allocates a new string on the heap, which is then returned
// abc + def -> abcdef\0
// NULL strings are treated as empty strings and overwritten/ignored
// except if both strings are NULL, in which case NULL is returned
char	*ft_str_add(char *s1, char *s2)
{
	int		len_one;
	int		len_two;
	char	*result;
	int		i;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	len_one = st_get_len(s1);
	len_two = st_get_len(s2);
	result = (char *)malloc((len_one + len_two + 1) * sizeof(char));
	i = -1;
	result[len_one] = '\0';
	while (++i < len_one)
		result[i] = s1[i];
	result[i] = '\0';
	i = -1;
	while (++i < len_two)
		result[i + len_one] = s2[i];
	result[i + len_one] = '\0';
	return (result);
}
