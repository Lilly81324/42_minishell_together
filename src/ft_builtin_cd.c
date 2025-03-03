/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_cd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:00:27 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/03 18:10:42 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Changes directory based off of <target>
// Creates new string consisting of current working directory (cwd)
// like this: <cwd>/<target> and then tries to navigate there
// such as: "../same_dir" or "new_dir" or "../../../../../home"
// Uses 2d array of tokens divided
static int	ft_rel_directory(char *target)
{
	char	*cwd;
	int		len_cwd;
	int		len_goal;
	char	*res;

	cwd = getcwd(NULL, 0);
	len_cwd = ft_strlen(cwd);
	if (cwd[0] == '/' && cwd[1] == '\0')
		len_cwd--;
	len_goal = ft_strlen(target);
	res = (char *)malloc((len_cwd + len_goal + 2) * sizeof(char));
	res[len_cwd + len_goal + 1] = '\0';
	len_goal++;
	while (--len_goal > 0)
		res[len_cwd + len_goal] = target[len_goal - 1];
	res[len_cwd + len_goal] = '/';
	len_cwd++;
	while (--len_cwd > 0)
		res[len_cwd - 1] = cwd[len_cwd -1];
	len_goal = chdir(res);
	ft_null(&cwd);
	ft_null(&res);
	return (len_goal);
}

// Prepares the key-value pair for the envp to update with
// returns that value
static char	*ft_new_envp_pwd(void)
{
	char	*cwd;
	int		len;
	char	*new;

	cwd = getcwd(NULL, 0);
	if (cwd == NULL)
		len = 0;
	else
		len = ft_strlen(cwd);
	new = (char *)malloc((len + 5) * sizeof(char));
	new[0] = 'P';
	new[1] = 'W';
	new[2] = 'D';
	new[3] = '=';
	new[len + 4] = '\0';
	while (--len >= 0)
		new[len + 4] = cwd[len];
	ft_null(&cwd);
	return (new);
}

// changes current directory to either an absolute or relative path
// as defined by the token after <tokens[*pos]>
int	ft_builtin_cd(char **tokens, int *pos, char ***envp)
{
	int		status;
	char	*new_cwd;

	(*pos)++;
	if (ft_is_del_or_red(tokens[*pos]) == 1)
		return (-1);
	if (tokens[*pos][0] == '/')
		status = chdir(tokens[*pos]);
	else
		status = ft_rel_directory(tokens[*pos]);
	if (status == 0)
		status = -1;
	else
	{
		printf(CD_INVALID_PATH, tokens[*pos]);
		status = 2;
	}
	(*pos)++;
	new_cwd = ft_new_envp_pwd();
	ft_change_env(envp, new_cwd);
	ft_null(&new_cwd);
	return (status);
}
