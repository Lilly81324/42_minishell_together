/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_cmds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:26:44 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/05 15:34:54 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Called at index <i> of first element of block <arg>
// Moves through all elements, ignoring everything that is a redirector
// Moves until it finds NULL or a non-redirector/command
// If it finds command then check wether its builtin
// then run the command
int	ft_token_cmds(char *arg[], int i, char ***envp)
{
	int	status;

	while (ft_is_delimiter(arg[i]) == 0)
	{
		if (ft_is_redirector(arg[i]) == 1)
			i += 2;
		else
		{
			if (ft_check_special(arg[i]) == 1)
				status = ft_special_cmd(arg, &i, envp);
			else if (ft_check_abs_cmds(arg, i) == 1)
				status = ft_absolute_cmd(arg, &i, envp);
			else
				status = ft_regular_cmd(arg, &i, envp);
			if (status != -1)
				return (status);
		}
	}
	return (-1);
}
