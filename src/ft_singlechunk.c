/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_singlechunk.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:09:13 by sikunne           #+#    #+#             */
/*   Updated: 2025/04/03 18:38:26 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_singlechunk(t_shell *shl, int *pos)
{
	int	status;

	status = ft_token_redirect(shl, *pos);
	if (status > 0)
		return (status);
	status = ft_token_cmds(shl, *pos, shl->env);
	while (ft_is_delimiter(shl->tok[*pos]) != 1)
		(*pos)++;
	return (status);
}
