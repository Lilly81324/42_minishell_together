/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:53:11 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/12 16:25:37 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// prints env variable
int	ft_builtin_env(t_shell *shl, int *pos)
{
	int	i;

	i = -1;
	if (ft_is_del_or_red(shl->tok[*pos + 1]) == 0)
		return (ft_too_many_args("env"));
	while ((*shl->env)[++i] != NULL)
		printf("%s\n", (*shl->env)[i]);
	(*pos)++;
	return (-1);
}
