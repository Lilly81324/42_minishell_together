/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_diff.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:13:12 by sikunne           #+#    #+#             */
/*   Updated: 2024/11/22 12:20:35 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

// takes care of differentitating the different cases
void	ft_handle_diff(const char *input, t_helper *h, va_list pargs)
{
	if (input[h->pos] == 'i' || input[h->pos] == 'd')
		h->sum += ft_print_int(va_arg(pargs, int));
	else if (input[h->pos] == 'u')
		h->sum += ft_print_unsint(va_arg(pargs, unsigned int));
	else if (input[h->pos] == 'x')
		h->sum += ft_print_x(va_arg(pargs, unsigned int));
	else if (input[h->pos] == 'X')
		h->sum += ft_print_xcap(va_arg(pargs, unsigned int));
	else if (input[h->pos] == 'c')
		h->sum += ft_print_char((char)va_arg(pargs, int));
	else if (input[h->pos] == 's')
		h->sum += ft_print_str((char *)va_arg(pargs, char *));
	else if (input[h->pos] == 'p')
		h->sum += ft_print_ptr((char *)va_arg(pargs, void *));
}
