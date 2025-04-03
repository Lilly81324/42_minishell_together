/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_export.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:17:47 by sikunne           #+#    #+#             */
/*   Updated: 2025/04/04 01:01:45 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	st_export_error(char *str)
{
	ft_perror(EXPORT_INVALID, str, NULL);
	return (0);
}

// if non valid identifier in there somewhere, error
// if valid but no = do nothing
// returns 1 if valid pair
// a vaild pair has at least one character and then a '='
static int	ft_check_key(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && (ft_isalpha(str[i]) != 0 || str[i] == '_'))
		i++;
	if (i <= 0)
		return (st_export_error(str));
	while (str[i] != '\0' && (ft_isalnum(str[i]) != 0 || str[i] == '_'))
		i++;
	if (str[i] == '\0')
		return (0);
	if (i <= 0 || str[i] != '=')
		return (st_export_error(str));
	return (1);
}

// handles the "export" builtin, which sets and adds certain
// key=value pairs in the envp
// export PATH=/usr/bin
// Auto corrects SHLVL to valid integer
int	ft_builtin_export(t_shell *shl, int *pos, char ***env)
{
	int	status;

	status = 0;
	(*pos)++;
	if (ft_is_del_or_red(shl->tok[*pos]) == 1)
	{
		ft_builtin_export_blank(*env);
		return (0);
	}
	while (ft_is_del_or_red(shl->tok[*pos]) == 0)
	{
		if (ft_check_key(shl->tok[*pos]) == 1)
		{
			ft_change_env(env, shl->tok[*pos]);
			status = 0;
		}
		else
			status = ERNUM_EXPORT_INVAL;
		(*pos)++;
	}
	return (status);
}
