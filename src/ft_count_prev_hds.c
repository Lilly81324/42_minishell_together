/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_prev_hds.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 19:32:01 by sikunne           #+#    #+#             */
/*   Updated: 2025/04/07 20:38:17 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Returns the number of "<<" tokens that is left of the <pos>
int	ft_count_prev_hds(t_shell *shl, int pos)
{
	int	count;

	count = 0;
	pos++;
	while (--pos >= 0)
	{
		if (ft_b_strcmp(shl->tok[pos], "<<") != 0)
			continue ;
		count++;
	}
	return (count);
}
