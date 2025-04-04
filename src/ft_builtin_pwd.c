/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_pwd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:25:52 by sikunne           #+#    #+#             */
/*   Updated: 2025/04/04 16:31:08 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// imitates behaviour of "pwd"
int	ft_builtin_pwd(int *pos)
{
	char	*pwd;

	(*pos)++;
	pwd = getcwd(NULL, 0);
	if (pwd == NULL)
	{
		ft_perror(PWD_NONEXISTENT_ERROR, NULL, NULL);
		return (ERNUM_PWD_NOTEXIST);
	}
	ft_write_string(pwd);
	ft_write_string("\n");
	ft_null(&pwd);
	return (0);
}
