/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_export.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:17:47 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/26 15:15:42 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// handles output of export with no arguments
// by printing out all the envp vaiables
static int	ft_print_env(char ***envp)
{
	int	i;
	int	j;

	i = 0;
	while ((*envp)[i] != NULL)
	{
		j = -1;
		printf("declare -x ");
		while ((*envp)[i][++j] != '=')
			printf("%c", (*envp)[i][j]);
		printf("=\"");
		while ((*envp)[i][++j] != '\0')
			printf("%c", (*envp)[i][j]);
		printf("\"");
		printf("\n");
		i++;
	}
	return (-1);
}

// handles the "export" builtin, which sets and adds certain
// key=value pairs in the envp
// export PATH=/usr/bin
int	ft_builtin_export(char **tokens, int *pos, char ***envp)
{
	(*pos)++;
	if (ft_is_del_or_red(tokens[*pos]) == 1)
		return(ft_print_env(envp));
	ft_change_env(envp, tokens[*pos]);
	(*pos)++;
	return (-1);
}
