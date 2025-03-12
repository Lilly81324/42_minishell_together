/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_cmds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:26:44 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/12 16:28:38 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Called at index <i> of first element of block <arg>
// Moves through all elements, ignoring everything that is a redirector
// Moves until it finds NULL or a non-redirector/command
// If it finds command then check wether its builtin
// then run the command
int	ft_token_cmds(t_shell *shl, int i)
{
	int	status;

	while (ft_is_delimiter(shl->tok[i]) == 0)
	{
		if (ft_is_redirector(shl->tok[i]) == 1)
			i += 2;
		else
		{
			if (ft_check_special(shl->tok[i]) == 1)
				status = ft_special_cmd(shl, &i);
			else if (ft_check_abs_cmds(shl->tok, i) == 1)
				status = ft_absolute_cmd(shl, &i);
			else
				status = ft_regular_cmd(shl, &i);
			if (status != -1)
				return (status);
		}
	}
	return (-1);
}
