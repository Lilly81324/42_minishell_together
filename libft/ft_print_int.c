/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:31:45 by sikunne           #+#    #+#             */
/*   Updated: 2024/11/22 12:20:27 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

// writes the integer num and returns bytes written
size_t	ft_print_int(int num)
{
	size_t	count;
	char	*base;

	count = 0;
	base = "0123456789";
	if (num == -2147483648)
	{
		ft_print_str("-2147483648");
		return (11);
	}
	if (num < 0)
	{
		num = num * -1;
		count += ft_print_char('-');
	}
	if (num >= 10)
		count += ft_print_int(num / 10);
	write(1, &base[num % 10], 1);
	count++;
	return (count);
}
