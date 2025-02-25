/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_specials.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:10:30 by sikunne           #+#    #+#             */
/*   Updated: 2024/11/22 12:20:34 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

// prepares the special variable so that it can be printed out
// checks if there is a second % in which case % is printed and sum increased
// otherwise it send it either to special_num or special_res
// depending on wether its a number or something different
int	ft_handle_specials(const char	*input, t_helper *h, va_list pargs)
{
	if (input[h->pos] != '\0' && input[h->pos] == '%')
	{
		h->sum += ft_print_char('%');
		h->pos++;
		return (0);
	}
	else if (input[h->pos] != '\0' && \
			ft_char_in_str("cspdiuxX", input[h->pos]) == 1)
	{
		ft_handle_diff(input, h, pargs);
		h->pos ++;
		return (0);
	}
	return (-1);
}
