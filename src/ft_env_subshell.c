/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_subshell.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:16:37 by sikunne           #+#    #+#             */
/*   Updated: 2025/04/04 14:13:27 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Creates new eviroment for each subshell
// This means <count> enviroments
// Does not reset _ enviroment var <-- CONTROVERSIAL
char	**ft_env_subshell(char ***src)
{
	int		i;
	char	**target;

	i = -1;
	target = ft_copy_env(*src);
	ft_env_decrease(&target, "SHLVL", -1);
	return (target);
}
