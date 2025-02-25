/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:07:25 by sikunne           #+#    #+#             */
/*   Updated: 2024/11/22 12:20:25 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

// writes out a string and returns bytes written
size_t	ft_print_str(char *str)
{
	int		i;
	size_t	sum;

	i = 0;
	sum = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i] != '\0')
	{
		sum += ft_print_char(str[i]);
		i++;
	}
	return (sum);
}
