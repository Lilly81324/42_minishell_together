/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 20:38:05 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/21 20:38:05 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// returns the index of a char <c> in the <string>
// returns -1 if not there or NULL
int	ft_find_c(char c, char *string)
{
	int	ret;

	ret = 0;
	if (string == NULL)
		return (-1);
	while (string[ret] != '\0' && string[ret] != c)
		ret++;
	if (string[ret] == '\0' && c != '\0')
		return (-1);
	return (ret);
}
