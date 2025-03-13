/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:30:24 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/13 16:54:13 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// writes out a string to perror
static void	st_perror_str(char *str)
{
	int		i;

	if (str == NULL)
		write(STDERR_FILENO, "(null)", 6 * sizeof(char));
	else
	{
		i = -1;
		while (str[++i] != '\0')
			write(STDERR_FILENO, &(str[i]), sizeof(char));
	}
}

// moves <pos> to next '%' or '\0'
// prints out the string until then to STDERR_FILENO
// sets pos to -1 if error allocating
// Be carefull of using pos if its -1 then
static void	st_handle_strings(const char *input, int *pos)
{
	size_t	len;
	char	*temp;
	int		i;

	len = 0;
	while (input[(*pos) + len] != '\0' && input[(*pos) + len] != '%')
		len++;
	temp = (char *)malloc((len + 1) * sizeof(char));
	if (temp == NULL)
	{
		(*pos) = -1;
		return ;
	}
	i = 0;
	while (input[*pos] != '%' && input[*pos] != '\0')
	{
		temp[i] = input[*pos];
		i++;
		(*pos)++;
	}
	temp[i] = '\0';
	st_perror_str(temp);
	free(temp);
	return ;
}

// perrors a string with at most 2 strings in it
// use like printf, except only with strings and at most 2
// ft_perror("This: %s isnt %s.\n", "apple", "banana")
// DO NOT use more %s in your string then valid strings given to the programm,
// It is a very weak function, dont stress it too much, it will break
// it doesnt even make a null check for input
void	ft_perror(char *input, char *arg1, char *arg2)
{
	int	pos;
	int	strcount;

	pos = 0;
	strcount = 0;
	while (input[pos] != '\0')
	{
		if (input[pos] != '%' && input[pos] != '\0')
			st_handle_strings(input, &pos);
		if (pos < 0 || input[pos] == '\0')
			return ;
		pos++;
		if (input[pos] == '%')
			write(STDERR_FILENO, "%%", sizeof(char));
		else if (input[pos] == 's' && strcount == 0)
		{
			st_perror_str(arg1);
			strcount++;
		}
		else
			st_perror_str(arg2);
		if (input[pos] != '\0')
			pos++;
	}
	return ;
}
