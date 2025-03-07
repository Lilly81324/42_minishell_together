/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:53:11 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/07 16:42:09 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// prints env variable
int	ft_builtin_env(char **tokens, int *pos, char ***envp)
{
	int	i;

	i = -1;
	while ((*envp)[++i] != NULL)
		printf("%s\n", (*envp)[i]);
	(*pos)++;
	if (ft_is_del_or_red(tokens[*pos]) == 0)
		return (ft_too_many_args("env"));
	return (-1);
}
