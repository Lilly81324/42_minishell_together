/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_last_arg.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:56:49 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/14 17:07:18 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_update_last_arg(t_shell *shl, char *arg)
{
	char	*last_arg;

	last_arg = ft_str_add("_=", arg);
	ft_change_env(shl->env, last_arg);
	ft_null(&last_arg);
}
