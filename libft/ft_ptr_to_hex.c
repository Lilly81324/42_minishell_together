/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_to_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:43:57 by sikunne           #+#    #+#             */
/*   Updated: 2024/11/22 12:21:23 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

// converts the address of the pointer to hexadecimal
// writes out the address of the given pointer to stdout
size_t	ft_ptr_to_hex(uintptr_t num)
{
	size_t	count;
	char	*base;

	count = 0;
	base = "0123456789abcdef";
	if (num >= 16)
		count += ft_ptr_to_hex(num / 16);
	write(1, &base[num % 16], 1);
	count++;
	return (count);
}
