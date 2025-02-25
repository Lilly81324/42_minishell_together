/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:17:00 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/06 23:43:17 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

// gives out how many digits a number is
static int	ft_st_get_len(int n)
{
	int	length;

	length = 1;
	if (n < 0)
		n *= -1;
	while (n / 10 > 0)
	{
		n /= 10;
		length++;
	}
	return (length);
}

// gives out a multiple of ten with times 0s
static int	ft_st_poweroften(int times)
{
	int	res;

	res = 1;
	while (times > 0)
	{
		res *= 10;
		times--;
	}
	return (res);
}

// goes through the integer and prints each..
// ..number until it reaches the last digit
static void	ft_st_dodigits(int n, int len, int fd)
{
	int	temp;

	temp = 0;
	while (len > 0)
	{
		temp = n / ft_st_poweroften(len - 1);
		temp += '0';
		write(fd, &temp, sizeof(char));
		temp -= '0';
		n -= temp * ft_st_poweroften(len - 1);
		len--;
	}
}

// gives the integer in the file descriptor fd out
void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = n * -1;
	}
	ft_st_dodigits(n, ft_st_get_len(n), fd);
}
