/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_export.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:17:47 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/06 18:10:23 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// returns 1 if valid pair
// a vaild pair has at least one character and then a '='
static int	ft_check_key(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '=')
		i++;
	if (str[i] == '\0' || i == 0)
		return (0);
	return (1);
}

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
		return (ft_print_env(envp));
	while (ft_is_del_or_red(tokens[*pos]) == 0)
	{
		if (ft_check_key(tokens[*pos]) == 1)
			ft_change_env(envp, tokens[*pos]);
		(*pos)++;
	}
	return (-1);
}
