/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:53:11 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/27 17:45:01 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// prints env variable
int	ft_builtin_env(t_shell *shl, int *pos)
{
	int	i;

	i = -1;
	shl->exit_code = 0;
	if (ft_is_del_or_red(shl->tok[*pos + 1]) == 0)
	{
		shl->exit_code = ERNUM_ENV_ARGC;
		return (ft_too_many_args("env", 0));
	}
	while ((*shl->env)[++i] != NULL)
	{
		ft_write_string((*shl->env)[i]);
		ft_write_string("\n");
	}
	(*pos)++;
	return (0);
}
