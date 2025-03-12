/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_absolute_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:03:44 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/12 17:24:08 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// allocates path for absolute commands and returns it
// needs to be freed 
static char	*st_prepare_path(char **token, int pos)
{
	char	*path;
	char	*pwd;

	pwd = NULL;
	if (token[pos][0] == '.' && token[pos][1] == '/')
	{
		pwd = getcwd(NULL, 0);
		path = ft_str_add(pwd, &(token[pos][1]));
	}
	else
		path = ft_strdup(token[pos]);
	ft_null(&pwd);
	return (path);
}

// handles error
// returns the error code or -1 if it works
static int	st_check_acces(char *path, char *cmd)
{
	int	exists;
	int	acces;

	acces = -1;
	exists = access(path, F_OK);
	if (exists != 0)
	{
		printf(INVALID_COMMAND, cmd);
		return (127);
	}
	acces = access(path, X_OK);
	if (acces != 0)
	{
		printf(FILE_EXECUTE_NO_PERMISSION, cmd);
		return (127);
	}
	return (-1);
}

// For running absolute commands like /usr/local/bin/norminette or ./minishell
// Waits for process to be done before giving back control
int	ft_absolute_cmd(t_shell *shl, int *pos)
{
	int		len;
	int		status;
	char	*path;
	char	**argv;

	path = st_prepare_path(shl->tok, *pos);
	status = st_check_acces(path, shl->tok[*pos]);
	if (status != -1)
	{
		ft_null(&path);
		return (status);
	}
	argv = ft_prepare_argv(shl->tok, pos);
	ft_run_cmd(path, argv, *shl->env, &status);
	ft_nullc(&argv);
	ft_null(&path);
	len = 0;
	while (ft_is_delimiter(shl->tok[len + (*pos)]) == 0)
		len++;
	(*pos) += len;
	return (status);
}
