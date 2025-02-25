/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:54:23 by sikunne           #+#    #+#             */
/*   Updated: 2024/11/22 12:26:12 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// for NULL and size_t
# include <stdlib.h>
// for variadic functions
# include <stdarg.h>
// for uintptr_t
# include <stdint.h>
// for write
# include <unistd.h>

typedef struct s_helper
{
	int				pos;
	int				sum;
}	t_helper;

int				ft_printf(const char *input, ...);

size_t			ft_percent_strlen(const char *str);
int				ft_char_in_str(const char *big, char little);
size_t			ft_ptr_to_hex(uintptr_t num);

int				ft_handle_strings(const char *input, t_helper *h);
int				ft_handle_specials(const char	*input, t_helper *h, \
				va_list pargs);
void			ft_handle_diff(const char *input, t_helper *h, va_list pargs);

size_t			ft_print_char(char c);
size_t			ft_print_str(char *str);
size_t			ft_print_ptr(void *ptr);
size_t			ft_print_int(int num);
size_t			ft_print_unsint(unsigned int num);
size_t			ft_print_x(unsigned int num);
size_t			ft_print_xcap(unsigned int num);

#endif
