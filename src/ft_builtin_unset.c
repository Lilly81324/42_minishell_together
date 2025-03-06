/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_unset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:52:20 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/06 18:17:18 by sikunne          ###   ########.fr       */
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

	(*pos)++;
	if (ft_is_del_or_red(tokens[*pos]) == 1)
		return (-1);
	while (ft_is_del_or_red(tokens[*pos]) == 0)
	{
		i = -1;
		while ((*envp)[++i] != NULL)
		{
			if (ft_strncmp((*envp)[i], tokens[*pos], \
				ft_strlen(tokens[*pos])) == 0 && \
				(*envp)[i][ft_strlen(tokens[*pos])] == '=')
			{
				ft_remove_env(envp, tokens[*pos]);
				break ;
			}
		}
		(*pos)++;
	}
	return (-1);
}
