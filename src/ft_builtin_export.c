/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_export.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:17:47 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/26 01:38:56 by sikunne          ###   ########.fr       */
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

// handles the "export" builtin, w	hich sets and adds certain
// key=value pairs in the envp
// export PATH=/usr/bin
int	ft_builtin_export(char **tokens, int *pos, char ***envp)
{
	(*pos)++;
	if (ft_is_delimiter(tokens[*pos]) == 1)
		return (ft_print_env(envp));
	if (ft_check_key(tokens[*pos]) == 1)
		ft_change_env(envp, tokens[*pos]);
	(*pos)++;
	return (-1);
}
