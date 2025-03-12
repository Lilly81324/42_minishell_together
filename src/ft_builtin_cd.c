/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_cd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:00:27 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/12 19:10:58 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Changes directory based off of <target>
// Creates new string consisting of current working directory (cwd)
// like this: <cwd>/<target> and then tries to navigate there
// such as: "../same_dir" or "new_dir" or "../../../../../home"
// Adds <cwd> + '/' + <target> and navigates there
static int	ft_rel_directory(char *target)
{
	char	*cwd;
	char	*temp;
	char	*res;
	int		status;

	cwd = getcwd(NULL, 0);
	temp = ft_str_add(cwd, "/");
	res = ft_str_add(temp, target);
	status = chdir(res);
	ft_null(&cwd);
	ft_null(&temp);
	ft_null(&res);
	return (status);
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

// called when running cd with no arguments
// moves pwd to HOME from envp
// prints out Error if no HOME
// and another Error if invalid home to move to
static int	ft_blank_cd(t_shell *shl)
{
	char	*home;
	int		status;
	char	*new_cwd;

	home = ft_get_env(*shl->env, "HOME");
	if (!home)
	{
		printf(CD_HOMELESS_ERROR);
		shl->exit_code = ERNUM_CD_HOMELESS;
		return (0);
	}
	status = chdir(home);
	if (status == -1)
	{
		printf(CD_INVALID_PATH, home);
		shl->exit_code = ERNUM_CD_HOMEWRONG;
		return (0);
	}
	new_cwd = ft_new_envp_pwd();
	ft_change_env(shl->env, new_cwd);
	ft_null(&new_cwd);
	return (0);
}

// changes current directory to either an absolute or relative path
// as defined by the token after <tokens[*pos]>
int	ft_builtin_cd(t_shell *shl, int *pos)
{
	int		status;
	char	*new_cwd;

	shl->exit_code = 0;
	(*pos)++;
	if (ft_is_del_or_red(shl->tok[*pos]) == 1)
		return (ft_blank_cd(shl));
	if (ft_is_del_or_red(shl->tok[(*pos) + 1]) == 0)
		return (ft_too_many_args("cd", ERNUM_CD_ARGC));
	if (shl->tok[*pos][0] == '/')
		status = chdir(shl->tok[*pos]);
	else
		status = ft_rel_directory(shl->tok[*pos]);
	if (status != 0)
	{
		printf(CD_INVALID_PATH, shl->tok[*pos]);
		shl->exit_code = ERNUM_CD_PATHWRONG;
		return (0);
	}
	(*pos)++;
	new_cwd = ft_new_envp_pwd();
	ft_change_env(shl->env, new_cwd);
	ft_null(&new_cwd);
	return (0);
}
