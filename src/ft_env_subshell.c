/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_subshell.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:16:37 by sikunne           #+#    #+#             */
/*   Updated: 2025/04/03 16:55:29 by sikunne          ###   ########.fr       */
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

	i = 0;
	target = (char ***)malloc((count + 1) * sizeof(char **));
	if (target == NULL)
		return (NULL);
	printf("Making %i enviroments\n", count);
	while (i < count)
	{
		printf("Setting env %i\n", i);
		temp = ft_copy_env(*src);
		ft_env_decrease(&temp, "SHLVL", -1);
		target[i] = temp;
	}
	printf("Setting last env to NULL %i\n", count);
	target[count] = NULL;
	return (target);
}
