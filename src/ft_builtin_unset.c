/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_unset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:52:20 by sikunne           #+#    #+#             */
/*   Updated: 2025/04/09 13:57:37 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// unsets/removes keys from the <envp>
// if no arguments, return, continue
// arguments has to be valid key
// if 1 argument is not valid key, return, continue
// if it is a valid key, then remove that key adn return, continue
int	ft_builtin_unset(t_shell *shl, int *pos, char ***env)
{
	int	i;

	(*pos)++;
	ft_skip_redirector(shl->tok, pos);
	if (ft_is_delimiter(shl->tok[*pos]) == 1)
		return (0);
	while (ft_is_delimiter(shl->tok[*pos]) == 0)
	{
		i = -1;
		ft_skip_redirector(shl->tok, pos);
		if (ft_is_delimiter(shl->tok[*pos]) == 1)
			break ;
		while ((*env)[++i] != NULL)
		{
			if (ft_strncmp((*env)[i], shl->tok[*pos], \
ft_strlen(shl->tok[*pos])) == 0 && \
(*env)[i][ft_strlen(shl->tok[*pos])] == '=')
			{
				ft_remove_env(env, shl->tok[*pos]);
				break ;
			}
		}
		(*pos)++;
	}
	return (0);
}
