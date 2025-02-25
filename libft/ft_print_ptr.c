/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:11:10 by sikunne           #+#    #+#             */
/*   Updated: 2024/11/22 12:20:28 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

// does error handling, before writing '0x'
// then calls the ptr_to_hex function which translates..
// .. and writes the hexadecimal
// returns bytes written
size_t	ft_print_ptr(void *ptr)
{
	size_t	res;

	res = 0;
	if (ptr == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	res = write(1, "0x", 2);
	if (res <= 0)
		return (0);
	res += ft_ptr_to_hex((uintptr_t)ptr);
	return (res);
}
