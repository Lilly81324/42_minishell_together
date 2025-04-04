/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_singlechunk.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:09:13 by sikunne           #+#    #+#             */
/*   Updated: 2025/04/04 13:51:34 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_singlechunk(t_shell *shl, int *pos)
{
	int	ex;

	ex = 0;
	shl->exit_code = ft_token_redirect(shl, *pos);
	if (shl->exit_code != 0)
		return (0);
	shl->exit_code = ft_token_cmds(shl, *pos, shl->env, &ex);
	while (ft_is_delimiter(shl->tok[*pos]) != 1)
		(*pos)++;
	if (ex != 0)
		return (2);
	return (0);
}
