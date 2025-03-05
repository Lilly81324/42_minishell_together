/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_absolute_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:03:44 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/05 18:14:05 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// allocates path for absolute commands
// needs to be freed 
static char	*ft_prepare_path(char **token, int pos)
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

static int	ft_run_cmd(char *path, char **argv, char ***envp)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		printf(FORK_ERROR);
		return (1);
	}
	if (pid == 0)
		execve(path, argv, *envp);
	waitpid(pid, NULL, 0);
	return (-1);
}

int	ft_absolute_cmd(char **token, int *pos, char ***envp)
{
	int		len;
	int		status;
	char	*path;
	char	**argv;

	path = ft_prepare_path(token, *pos);
	printf("Path defined: %s\n", path);
	argv = ft_prepare_argv(token, pos);
	status = ft_run_cmd(path, argv, envp);
	ft_nullc(&argv);
	ft_null(&path);
	len = 0;
	while (ft_is_delimiter(token[len + (*pos)]) == 0)
		len++;
	(*pos) += len;
	return (status);
}
