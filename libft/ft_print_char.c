/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:40:13 by sikunne           #+#    #+#             */
/*   Updated: 2024/11/22 12:20:29 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

// writes the character c and returns bytes written
size_t	ft_print_char(char c)
{
	size_t	res;

	res = write (1, &c, 1);
	if (res <= 0)
		return (0);
	else
		return (res);
}
