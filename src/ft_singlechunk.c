/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_singlechunk.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:09:13 by sikunne           #+#    #+#             */
/*   Updated: 2025/04/03 17:38:25 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_singlechunk(t_shell *shl, int *pos)
{
	int	status;

	status = 0;
	printf("Single Chunk Command\n");
	status = ft_token_redirect(shl, 0);
	if (status > 0)
		return (status);
	status = ft_token_cmds(shl, 0, shl->env);
	while (ft_is_delimiter(shl->tok[*pos]) != 1)
		(*pos)++;
	return (status);
}
