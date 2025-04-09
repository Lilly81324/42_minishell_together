/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_absolute_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:03:44 by sikunne           #+#    #+#             */
/*   Updated: 2025/04/09 13:56:34 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	st_dotcheck(char *tok)
{
	if (tok == NULL)
		return (0);
	if (tok[0] == '\0')
		return (0);
	if (tok[0] == '.' && tok[1] == '\0')
	{
		ft_perror("lelshell: .: filename argument required \n%s\n", \
".: usage: . filename [arguments]", NULL);
		return (1);
	}
	if (ft_b_strcmp(tok, "..") == 0)
	{
		ft_perror(INVALID_COMMAND, "..", NULL);
		return (ERNUM_CMD_NOTEXIST);
	}
	return (0);
}

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
int	ft_absolute_cmd(t_shell *shl, int *pos, char ***env)
{
	int		len;
	int		status;
	char	*path;
	char	**argv;

	status = st_dotcheck(shl->tok[*pos]);
	if (status != 0)
		return (status);
	path = st_prepare_path(shl->tok, *pos);
	status = ft_check_access(path, shl->tok[*pos]);
	if (status != 0)
	{
		ft_null(&path);
		return (status);
	}
	argv = ft_prepare_argv(shl->tok, pos);
	status = ft_run_cmd(path, argv, env);
	ft_nullc(&argv);
	ft_null(&path);
	len = 0;
	while (ft_is_delimiter(shl->tok[len + (*pos)]) == 0)
		len++;
	(*pos) += len;
	return (status);
}
