/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:53:11 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/24 15:47:30 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// prints env variable
int	ft_builtin_env(int *pos, char ***envp)
{
	int	i;

	i = -1;
	while ((*envp)[++i] != NULL)
		printf("%s\n", (*envp)[i]);
	(*pos)++;
	return (-1);
}// WARNING env just returns its own env variable
// it does not look exactly like what you would get in bash