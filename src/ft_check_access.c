/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_access.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:37:47 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/31 18:23:48 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// handles error cases and prints them
// returns the error code or 0 if it works
int	ft_check_access(char *path, char *cmd)
{
	int	exists;
	int	acces;

	acces = -1;
	exists = access(path, F_OK);
	if (exists != 0)
	{
		if (ft_check_abs_cmds(&cmd, 0) == 0)
			ft_perror(INVALID_COMMAND, cmd, NULL);
		else
			ft_perror(NO_SUCH_FILE, cmd, NULL);
		return (ERNUM_CMD_NOTEXIST);
	}
	if (ft_is_directory(path) == 1)
	{
		ft_perror(CMD_IS_DIR, cmd, NULL);
		return (ERNUM_CMD_IS_DIR);
	}
	acces = access(path, X_OK);
	if (acces != 0)
	{
		ft_perror(FILE_EXECUTE_NO_PERMISSION, cmd, NULL);
		return (ERNUM_CMD_PERM);
	}
	return (0);
}
