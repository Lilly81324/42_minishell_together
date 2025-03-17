/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_export.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:17:47 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/17 18:33:31 by sikunne          ###   ########.fr       */
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
		ft_perror(EXPORT_INVALID, str, NULL);
		return (0);
	}
	return (1);
}

// Called when trying to export a valid key
// Atois the value after the first '='
// Tries to set SHLVL to that number or 0 if not possible
// ATTENTION If you want to reduce the exported number by one,
// make sure that you arent reducing 0 by -1 too
static void	st_prepare_exporting(t_shell *shl, int *pos)
{
	int		shlvl;
	char	*number;
	char	*result;

	shlvl = 1;
	if (ft_strncmp("SHLVL=", shl->tok[*pos], 6) == 0)
	{
		shlvl = ft_atoi_shlvl(shl->tok[*pos]);
		number = ft_itoa(shlvl);
		result = ft_str_add("SHLVL=", number);
		ft_change_env(shl->env, result);
		ft_null(&number);
		ft_null(&result);
	}
	else
		ft_change_env(shl->env, shl->tok[*pos]);
}

// handles the "export" builtin, which sets and adds certain
// key=value pairs in the envp
// export PATH=/usr/bin
// Auto corrects SHLVL to valid integer
int	ft_builtin_export(t_shell *shl, int *pos)
{
	(*pos)++;
	shl->exit_code = 0;
	if (ft_is_del_or_red(shl->tok[*pos]) == 1)
	{
		ft_builtin_export_blank(*shl->env);
		return (0);
	}
	while (ft_is_del_or_red(shl->tok[*pos]) == 0)
	{
		if (ft_check_key(shl->tok[*pos]) == 1)
			st_prepare_exporting(shl, pos);
		else
			shl->exit_code = ERNUM_EXPORT_INVAL;
		(*pos)++;
	}
	return (0);
}
