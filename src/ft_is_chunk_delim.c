/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_chunk_delim.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 17:47:33 by sikunne           #+#    #+#             */
/*   Updated: 2025/04/03 17:51:01 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Returns same value as ft_is_delimiter, except for pipes
int	ft_is_chunk_delim(char *str)
{
	if (ft_is_delimiter(str) == 0)
		return (0);
	if (str == NULL)
		return (1);
	if (str[0] == '\0')
		return (0);
	if (str[0] == '|' && str[1] == '\0')
		return (0);
	return (1);
}
