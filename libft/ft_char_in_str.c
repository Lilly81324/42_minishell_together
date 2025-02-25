/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_in_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:51:22 by sikunne           #+#    #+#             */
/*   Updated: 2024/11/22 12:20:33 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

// returns a 1 if character little was found in string big
// otherwise returns a 0
int	ft_char_in_str(const char *big, char little)
{
	int	i;

	i = 0;
	if (big == NULL)
		return (0);
	while (big[i] != '\0')
	{
		if (big[i] == little)
			return (1);
		i++;
	}
	return (0);
}
