/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_strings.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:36:33 by sikunne           #+#    #+#             */
/*   Updated: 2024/11/22 12:20:37 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

// handles the strings of the input
// uses the helper structures pos attribute to count and move where it is
// allocs a string based on current pos and EOF or next % sign
// if Allocation failes return -1
// iterate through the input and save every letter until EOF or %..
// ..into a string, then writes that string
// increases sum of written bytes in helper structure accordingly
int	ft_handle_strings(const char *input, t_helper *h)
{
	size_t	len;
	char	*temp;
	int		i;

	len = ft_percent_strlen(&input[h->pos]);
	temp = (char *)malloc((len + 1) * sizeof(char));
	if (temp == NULL)
		return (-1);
	i = 0;
	while (input[h->pos] != '%' && input[h->pos] != '\0')
	{
		temp[i] = input[h->pos];
		i++;
		h->pos++;
	}
	temp[i] = '\0';
	h->sum += ft_print_str(temp);
	free(temp);
	return (0);
}
