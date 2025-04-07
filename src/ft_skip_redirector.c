/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_redirector.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:38:42 by sikunne           #+#    #+#             */
/*   Updated: 2025/04/04 15:44:45 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Skips past redirector in <tok> at <pos>
// If not called at redirector does nothing
// If called at ">" from ">", "file", NULL
// skips to NULL (+2)
// If called at ">" from ">", NULL
// also skips to NULL (+1)
void	ft_skip_redirector(char **tok, int *pos)
{
	while (ft_is_redirector(tok[*pos]) == 1)
	{
		(*pos)++;
		if (ft_is_delimiter(tok[*pos]) == 1)
			continue ;
		(*pos)++;
	}
}
