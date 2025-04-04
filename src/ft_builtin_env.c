/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:53:11 by sikunne           #+#    #+#             */
/*   Updated: 2025/04/04 16:07:46 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// prints env variable
int	ft_builtin_env(t_shell *shl, int *pos, char ***env)
{
	int	i;

	i = -1;
	(*pos)++;
	ft_skip_redirector(shl->tok, pos);
	if (ft_is_delimiter(shl->tok[*pos]) == 0)
		return (ft_too_many_args("env", ERNUM_ENV_ARGC));
	while ((*env)[++i] != NULL)
	{
		ft_write_string((*env)[i]);
		ft_write_string("\n");
	}
	return (0);
}
