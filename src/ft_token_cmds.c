/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_cmds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:26:44 by sikunne           #+#    #+#             */
/*   Updated: 2025/04/04 15:50:13 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Called at token <i> of <shl->tok>
// Moves through all elements, ignoring everything that is a redirector
// Moves until it finds NULL or a non-redirector/command
// If it finds command then check wether its builtin
// then runs the command
// returns the exit code of that command
// sets <*ex> to 1 if program should quit
int	ft_token_cmds(t_shell *shl, int i, char ***envp, int *ex)
{
	int	ex_code;

	while (ft_is_delimiter(shl->tok[i]) == 0)
	{
		ft_skip_redirector(shl->tok, &i);
		if (ft_is_delimiter(shl->tok[i]) == 1)
			return (0);
		if (ft_builtin_check(shl->tok[i]) == 1)
			ex_code = ft_builtin_cmd(shl, &i, envp, ex);
		else if (ft_check_abs_cmds(shl->tok, i) == 1)
			ex_code = ft_absolute_cmd(shl, &i, envp);
		else
			ex_code = ft_regular_cmd(shl, &i, envp);
		return (ex_code);
	}
	return (0);
}
