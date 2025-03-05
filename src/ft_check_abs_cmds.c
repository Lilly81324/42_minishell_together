/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_abs_cmds.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:18:14 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/05 15:24:36 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// returns 1 if absolute command like /usr/bin/echo
// or ./a.out
// or 0 if not
int	ft_check_abs_cmds(char **token, int pos)
{
	if (token[pos] == NULL || ft_strlen(token[pos]) < 3)
		return (0);
	if (token[pos][0] == '/')
		return (1);
	if (token[pos][0] == '.' && token[pos][1] == '/')
		return (1);
	return (0);
}
