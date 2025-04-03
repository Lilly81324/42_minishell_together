/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_singlechunk.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:24:59 by sikunne           #+#    #+#             */
/*   Updated: 2025/04/03 15:59:05 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// maybe change to count_pipes, same use case here, but more later
int	ft_check_singlechunk(char **tok, int pos)
{
	int	i;

	i = -1;
	while (ft_is_delimiter(tok[++i + pos]) == 0)
	{
		if (ft_b_strcmp(tok[i + pos], "|") == 0)
			return (0);
	}
	return (1);
}