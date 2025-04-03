/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_pipes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:24:59 by sikunne           #+#    #+#             */
/*   Updated: 2025/04/03 16:35:55 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// counts how many pipes between <tok[pos]> and next delim
int	ft_count_pipes(char **tok, int pos)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (ft_is_delimiter(tok[++i + pos]) == 0)
	{
		if (ft_b_strcmp(tok[i + pos], "|") == 0)
			count++;
	}
	return (count);
}