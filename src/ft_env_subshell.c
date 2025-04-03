/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_subshell.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:16:37 by sikunne           #+#    #+#             */
/*   Updated: 2025/04/03 18:23:19 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Creates new eviroment for each subshell
// This means <count> enviroments
// Does not reset _ enviroment var <-- CONTROVERSIAL
char	***ft_env_subshell(char ***src, int count)
{
	int		i;
	char	***target;
	char	**temp;

	i = -1;
	target = (char ***)malloc((count + 1) * sizeof(char **));
	if (target == NULL)
		return (NULL);
	while (++i < count)
	{
		temp = ft_copy_env(*src);
		ft_env_decrease(&temp, "SHLVL", -1);
		target[i] = temp;
	}
	target[count] = NULL;
	return (target);
}
