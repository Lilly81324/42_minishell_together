/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_unset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:52:20 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/24 17:12:19 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// unsets/removes keys from the <envp>
// if no arguments, return, continue
// arguments has to be valid key
// if 1 argument is not valid key, return, continue
// if it is a valid key, then remove that key adn return, continue
int	ft_builtin_unset(char **tokens, int *pos, char ***envp)
{
	int	i;
	int	index;

	(*pos)++;
	if (ft_is_delimiter(tokens[*pos]) == 1)
		return(-1);
	i = -1;
	while ((*envp)[++i] != NULL)
	{
		index = ft_find_c('=', (*envp)[i]);
		if (index < 0)
			continue;
		if (ft_strncmp(tokens[*pos], (*envp)[i], index) == 0)
			ft_remove_env(envp, tokens[*pos]);
	}
	(*pos)++;
	return (-1);
}

