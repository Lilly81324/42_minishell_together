/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:15:02 by sikunne           #+#    #+#             */
/*   Updated: 2024/11/16 11:10:03 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

// This function counts how many blocks of..
// ..text are delimited by start of string, the character..
// ..water or the end of file. It returns that number
static int	ft_st_get_sets(char const *sea, char water)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	if (sea == NULL)
		return (0);
	while (sea[i] != '\0')
	{
		if (sea[i] != water)
			counter++;
		while (sea[i] != water && sea[i] != '\0')
			i++;
		while (sea[i] == water && sea[i] != '\0')
			i++;
	}
	return (counter);
}

// This function is only called when a block..
// ..of text is supposed to be made into a substring.
// It returns the position where that block ends or..
// ..-1 if Allocation failed
static int	ft_st_splitter(char const *s, char c, int pos, char **result)
{
	int	arrpos;
	int	size;

	arrpos = 0;
	size = 0;
	while (s[pos + size] != c && s[pos + size] != '\0')
		size++;
	while (result[arrpos] != NULL)
		arrpos++;
	result[arrpos] = (char *)malloc((size + 1) * sizeof(char));
	if (result[arrpos] == NULL)
		return (-1);
	size = 0;
	while (s[pos] != c && s[pos] != '\0')
	{
		result[arrpos][size] = s[pos];
		size++;
		pos++;
	}
	result[arrpos][size] = '\0';
	return (pos);
}

// This function is called, when allocating...
// ...a string failed. It frees all strings up to..
// ...that one, frees result and returns a NULL
static char	**ft_st_free_result(char **result, int count)
{
	int	i;

	i = 0;
	while (i < count && result[i] != NULL)
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (NULL);
}

// This function is the central function, it uses...
// ...the other functions to split a string into...
// smaller strings and returns that array of arrays
char	**ft_split(char const *s, char c)
{
	int		pos;
	int		count;
	char	**result;

	pos = -1;
	if (s == NULL)
		return (NULL);
	count = ft_st_get_sets(s, c);
	result = (char **)malloc((count + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	while (++pos < count + 1)
		result[pos] = NULL;
	pos = 0;
	while (s[pos] != '\0')
	{
		if (s[pos] != c)
			pos = ft_st_splitter(s, c, pos, result);
		if (pos == -1)
			return (ft_st_free_result(result, count));
		while (s[pos] == c && s[pos] != '\0')
			pos++;
	}
	return (result);
}

// int	main(int argc, char *argv[0])
// {
// 	int		i;
// 	char	**result;

// 	i = 0;
// 	if (argc <= 1)
// 		return (0);
// 	result = ft_split("\0aa\0bbb", '\0');
// 	while (result[i] != NULL)
// 	{
// 		printf("%s\n", result[i]);
// 		i++;
// 	}
// 	return (0);
// }
