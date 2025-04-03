/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_del_or_red.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:48:00 by sikunne           #+#    #+#             */
/*   Updated: 2025/04/03 15:38:38 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// returns 1 if string is exactly
// NULL, ">", "<", "|", ":", ">>" or "<<"
// otherwise returns 0
int	ft_is_del_or_red(char *str)
{
	int	sum;

	sum = ft_is_delimiter(str) + ft_is_redirector(str);
	if (sum == 0)
		return (0);
	return (1);
}
