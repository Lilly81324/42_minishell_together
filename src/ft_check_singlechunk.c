/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_singlechunk.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:24:59 by sikunne           #+#    #+#             */
/*   Updated: 2025/04/02 15:28:17 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_singlechunk(char **tok)
{
	int	i;

	i = -1;
	while (tok[++i] != NULL)
	{
		if (ft_b_strcmp(tok[i], "|") == 0)
			return (0);
	}
	return (1);
}