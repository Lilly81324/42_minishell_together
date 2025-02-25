/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:08:47 by sikunne           #+#    #+#             */
/*   Updated: 2024/11/14 13:58:11 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

// because I would need 26 lines in ft_itoa, this gets...
// ...its own function, it just gives out "'0''\0'" on the given string
static char	*ft_st_nulls(char *string)
{
	string[0] = '0';
	string[1] = '\0';
	return (string);
}

// gives out how many digits long a certain number is
// adds one more digit if the number is neg
static int	ft_st_get_len(int n)
{
	int	length;

	length = 1;
	if (n < 0)
		length++;
	if (n > 0)
		n *= -1;
	while (n / 10 < 0)
	{
		n /= 10;
		length++;
	}
	return (length);
}

// takes a number, calculates it length,..
// ...allocates a string that size...
// ...and adds numbers to string from the right
char	*ft_itoa(int n)
{
	int		num;
	int		length;
	char	*result;
	int		i;

	length = ft_st_get_len(n);
	result = (char *)malloc((length + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	num = n;
	if (n == 0)
		return (ft_st_nulls(result));
	if (n > 0)
		num *= -1;
	i = 1;
	while (num < 0)
	{
		result[length - i] = ((-(num % 10)) + '0');
		num /= 10;
		i++;
	}
	if (n < 0)
		result[0] = '-';
	result[length] = '\0';
	return (result);
}

// #include <stdio.h>
// 
// int	main(void)
// {
// 	int	n;
// 
// 	n = -2147483648;
// 	printf("%s", ft_itoa(n));
// }
