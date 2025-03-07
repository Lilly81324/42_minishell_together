/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:23:06 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/07 19:16:04 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// creates a name by writing <path + / + name>
// so <usr/bin/ls> into a string and returning it for use
static char	*ft_make_name(char *path, char *name)
{
	char	*full_path;

	full_path = (char *)malloc((ft_strlen(path) + ft_strlen(name) \
								+ 2) * sizeof(char));
	ft_strlcpy(full_path, path, ft_strlen(path) + 1);
	ft_strlcpy(full_path + ft_strlen(full_path), "/", 2);
	ft_strlcpy(full_path + ft_strlen(full_path), name, ft_strlen(name) + 1);
	return (full_path);
}

// Checks wether a given Command "name" is found in any
// of the path variables from paths
// returns either the full path+command as string
// or NULL if error
// gives out error codes for file not found and/or no permission to execute
static char	*ft_check_access(char **paths, char *name)
{
	int		i;
	int		exists;
	int		acces;
	char	*full_path;

	i = -1;
	while (paths[++i] != NULL)
	{
		exists = -1;
		acces = -1;
		full_path = ft_make_name(paths[i], name);
		exists = access(full_path, F_OK);
		if (exists == 0)
		{
			acces = access(full_path, X_OK);
			if (acces == 0)
				return (full_path);
		}
		ft_null(&full_path);
	}
	if (exists != 0)
		return (NULL);
	if (exists == 0 && acces != 0)
		return (NULL);
	return (NULL);
}

// Tries to find the path of the binary  of the given command
// from the enviroment pointer (PATHS) and returns
// the path with the file, so /usr/bin/ls
char	*ft_get_path(char *cmd, char ***envp)
{
	char	*env_path;
	char	**paths;
	char	*path;

	if (cmd == NULL || cmd[0] == '\0')
		return (NULL);
	cmd = ft_strip(SPACES, cmd);
	if (cmd == NULL)
		return (NULL);
	env_path = ft_get_env(*envp, "PATH");
	paths = ft_split(env_path, ':');
	if (paths == NULL)
	{
		ft_null(&cmd);
		return (NULL);
	}
	path = ft_check_access(paths, cmd);
	ft_null(&cmd);
	ft_nullb(&paths);
	return (path);
}
