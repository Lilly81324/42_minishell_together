/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:38:34 by sikunne           #+#    #+#             */
/*   Updated: 2024/11/22 12:24:34 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

// writes out an unsigned int and returns bytes written
size_t	ft_print_unsint(unsigned int num)
{
	size_t	count;
	char	*base;

	count = 0;
	base = "0123456789";
	if (num >= 10)
		count += ft_print_unsint(num / 10);
	write(1, &base[num % 10], 1);
	count++;
	return (count);
}
