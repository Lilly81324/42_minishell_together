/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_last_arg.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:56:49 by sikunne           #+#    #+#             */
/*   Updated: 2025/04/03 17:40:04 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_update_last_arg(char *arg, char ***env)
{
	char	*last_arg;

	last_arg = ft_strjoin("_=", arg);
	ft_change_env(env, last_arg);
	ft_null(&last_arg);
}
