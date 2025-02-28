/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_del_or_red.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:48:00 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/28 18:28:19 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// returns 1 if string is exactly
// NULL, ">", "<", "|", ":", ">>" or "<<"
// otherwise returns 0
int	ft_is_del_or_red(char *str)
{
	if (str == NULL)
		return (1);
	if (str[0] == '\0')
		return (0);
	if (str[0] == '>' && str[1] == '\0')
		return (1);
	if (str[0] == '<' && str[1] == '\0')
		return (1);
	if (str[0] == '|' && str[1] == '\0')
		return (1);
	if (str[0] == ';' && str[1] == '\0')
		return (1);
	else if (str[1] == '\0')
		return (0);
	if (str[0] == '>' && str[1] == '>' && str[2] == '\0')
		return (1);
	if (str[0] == '<' && str[1] == '<' && str[2] == '\0')
		return (1);
	return (0);
}
