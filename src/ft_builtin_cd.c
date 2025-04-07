/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_cd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:00:27 by sikunne           #+#    #+#             */
/*   Updated: 2025/04/04 15:22:45 by sikunne          ###   ########.fr       */
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
	temp = ft_strjoin(cwd, "/");
	res = ft_strjoin(temp, target);
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
static int	ft_blank_cd(char ***env)
{
	char	*home;
	int		status;
	char	*new_cwd;

	home = ft_get_env(*env, "HOME");
	if (!home)
	{
		ft_perror(CD_HOMELESS_ERROR, NULL, NULL);
		return (ERNUM_CD_HOMELESS);
	}
	status = chdir(home);
	if (status == -1)
	{
		ft_perror(CD_INVALID_PATH, home, NULL);
		return (ERNUM_CD_HOMEWRONG);
	}
	new_cwd = ft_new_envp_pwd();
	ft_change_env(env, new_cwd);
	ft_null(&new_cwd);
	return (0);
}

// needed more lines again
static void	st_cleanup(t_shell *shl, int *pos)
{
	char	*new_cwd;

	new_cwd = ft_new_envp_pwd();
	ft_change_env(shl->env, new_cwd);
	ft_null(&new_cwd);
	(*pos)++;
}

// changes current directory to either an absolute or relative path
// as defined by the token after <tokens[*pos]>
int	ft_builtin_cd(t_shell *shl, int *pos, char ***env)
{
	int		status;
	int		after;

	(*pos)++;
	after = 1;
	while (ft_is_redirector(shl->tok[*pos]) == 1)
		(*pos) += 2;
	if (ft_is_delimiter(shl->tok[*pos]) == 1)
		return (ft_blank_cd(env));
	while (ft_is_redirector(shl->tok[(*pos) + after]) == 1)
		after += 2;
	if (ft_is_delimiter(shl->tok[(*pos) + after]) == 0)
		return (ft_too_many_args("cd", ERNUM_CD_ARGC));
	if (shl->tok[*pos][0] == '/')
		status = chdir(shl->tok[*pos]);
	else
		status = ft_rel_directory(shl->tok[*pos]);
	if (status != 0)
	{
		ft_perror(CD_INVALID_PATH, shl->tok[*pos], NULL);
		return (ERNUM_CD_PATHWRONG);
	}
	st_cleanup(shl, pos);
	return (0);
}
