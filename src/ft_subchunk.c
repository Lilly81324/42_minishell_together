/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subchunk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:38:35 by sikunne           #+#    #+#             */
/*   Updated: 2025/04/03 18:37:47 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_subchunk(t_shell *shl, int *pos, char ***env)
{
	int	status;

	status = ft_token_redirect(shl, *pos);
	if (status > 0)
		return (status);
	status = ft_token_cmds(shl, *pos, env);
	while (ft_is_delimiter(shl->tok[*pos]) != 1)
		(*pos)++;
	return (status);
}

