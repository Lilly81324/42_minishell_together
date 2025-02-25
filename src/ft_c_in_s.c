/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_in_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:51:22 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/13 16:59:22 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// returns a 1 if character little was found in string big
// otherwise returns a 0
int	ft_c_in_s(char *big, char little)
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
