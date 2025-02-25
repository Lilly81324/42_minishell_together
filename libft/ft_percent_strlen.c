/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent_strlen.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:50:13 by sikunne           #+#    #+#             */
/*   Updated: 2024/11/22 12:20:39 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

// gives out length of string or substring until a % sign
size_t	ft_percent_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0' && str[len] != '%')
		len++;
	return (len);
}
