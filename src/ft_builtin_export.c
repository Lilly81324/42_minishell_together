/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_export.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:17:47 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/12 19:05:51 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// if non valid identifier in there somewhere, error
// if valid but no = do nothing
// returns 1 if valid pair
// a vaild pair has at least one character and then a '='
static int	ft_check_key(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && (ft_isalnum(str[i]) != 0 || str[i] == '_'))
		i++;
	if (str[i] == '\0')
		return (0);
	if (i <= 0 || str[i] != '=')
	{
		printf(EXPORT_INVALID, str);
		return (0);
	}
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
	return (0);
}

// handles the "export" builtin, which sets and adds certain
// key=value pairs in the envp
// export PATH=/usr/bin
int	ft_builtin_export(t_shell *shl, int *pos)
{
	(*pos)++;
	shl->exit_code = 0;
	if (ft_is_del_or_red(shl->tok[*pos]) == 1)
		return (ft_print_env(shl->env));
	while (ft_is_del_or_red(shl->tok[*pos]) == 0)
	{
		if (ft_check_key(shl->tok[*pos]) == 1)
			ft_change_env(shl->env, shl->tok[*pos]);
		else
			shl->exit_code = ERNUM_EXPORT_INVAL;
		(*pos)++;
	}
	return (0);
}// exporting without arguments gives back strings in alpabetical order