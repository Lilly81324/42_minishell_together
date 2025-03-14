/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_special_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:59:55 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/14 19:10:47 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Updates _ for the builtins
// Move to next delimiter or redirector and the one back
// to reach the last given argument, then update _ with that
static void	st_update_last_arg(t_shell *shl, int pos)
{
	while (ft_is_del_or_red(shl->tok[pos]) == 0)
		pos++;
	if (pos > 0)
		pos--;
	ft_update_last_arg(shl, shl->tok[pos]);
}

// runs builtin commands like exit, cd, unset
// returns 0-255 if programm should close with that code
// returns -1 if programm should continue
int	ft_special_cmd(t_shell *shl, int *pos)
{
	int	i;
	int status;

	i = 0;
	ft_skip_spaces(&i, shl->tok[*pos]);
	if (ft_strncmp(&(shl->tok[*pos][i]), "exit", 4) == 0)
		status = ft_builtin_exit(shl, pos);
	else if (ft_strncmp(&(shl->tok[*pos][i]), "env", 3) == 0)
		status = ft_builtin_env(shl, pos);
	else if (ft_strncmp(&(shl->tok[*pos][i]), "pwd", 3) == 0)
		status = ft_builtin_pwd(shl, pos);
	else if (ft_strncmp(&(shl->tok[*pos][i]), "cd", 2) == 0)
		status = ft_builtin_cd(shl, pos);
	else if (ft_strncmp(&(shl->tok[*pos][i]), "export", 6) == 0)
		status = ft_builtin_export(shl, pos);
	else if (ft_strncmp(&(shl->tok[*pos][i]), "unset", 5) == 0)
		status = ft_builtin_unset(shl, pos);
	else if (ft_strncmp(&(shl->tok[*pos][i]), "history", 7) == 0)
		status = ft_builtin_history(shl, pos);
	else
		status = ft_builtin_echo(shl, pos);
	st_update_last_arg(shl, *pos);
	return (status);
}
