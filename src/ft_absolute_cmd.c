/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_absolute_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:03:44 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/18 16:56:02 by sikunne          ###   ########.fr       */
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
		path = ft_strjoin(pwd, &(token[pos][1]));
	}
	else
		path = ft_strdup(token[pos]);
	ft_null(&pwd);
	return (path);
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
	status = ft_check_access(path, shl->tok[*pos]);
	if (status != 0)
	{
		ft_null(&path);
		shl->exit_code = status;
		return (0);
	}
	argv = ft_prepare_argv(shl->tok, pos);
	status = ft_run_cmd(shl, path, argv);
	ft_nullc(&argv);
	ft_null(&path);
	len = 0;
	while (ft_is_delimiter(shl->tok[len + (*pos)]) == 0)
		len++;
	(*pos) += len;
	return (status);
}
