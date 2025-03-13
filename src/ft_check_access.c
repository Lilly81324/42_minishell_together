/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_access.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:37:47 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/12 19:39:34 by sikunne          ###   ########.fr       */
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
		printf(INVALID_COMMAND, cmd);
		return (ERNUM_CMD_NOTEXIST);
	}
	acces = access(path, X_OK);
	if (acces != 0)
	{
		printf(FILE_EXECUTE_NO_PERMISSION, cmd);
		return (ERNUM_CMD_PERM);
	}
	return (0);
}
