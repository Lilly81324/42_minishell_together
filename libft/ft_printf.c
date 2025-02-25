/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:32:28 by sikunne           #+#    #+#             */
/*   Updated: 2024/11/22 12:16:08 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

// searches input string for % signs with identifiers and..
// ..prints out the given arguments as that identifier
int	ft_printf(const char *input, ...)
{
	t_helper		h;
	va_list			pargs;

	h.pos = 0;
	h.sum = 0;
	va_start(pargs, input);
	while (input[h.pos] != '\0')
	{
		if (input[h.pos] != '%' && input[h.pos] != '\0')
			ft_handle_strings(input, &h);
		if (input[h.pos] == '%')
		{
			h.pos++;
			ft_handle_specials(input, &h, pargs);
		}
	}
	va_end(pargs);
	return ((int)h.sum);
}
