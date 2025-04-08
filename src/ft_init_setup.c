/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_setup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:29:56 by sikunne           #+#    #+#             */
/*   Updated: 2025/04/08 19:35:21 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Sets up the inital PWD variable
static void	st_initial_pwd(char ***env)
{
	char	*pwd;
	char	*new_pwd;

	if (ft_get_env((*env), "PWD") != NULL)
		return ;
	pwd = getcwd(NULL, 0);
	new_pwd = ft_strjoin("PWD=", pwd);
	ft_change_env(env, new_pwd);
	ft_null(&pwd);
	ft_null(&new_pwd);
}

// Sets up inital values for the enviroment
void	ft_init_setup(char ***env)
{
	ft_initial_shlvl(env);
	st_initial_pwd(env);
}
