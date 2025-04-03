/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_pwd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:25:52 by sikunne           #+#    #+#             */
/*   Updated: 2025/04/04 00:39:19 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// imitates behaviour of "pwd"
int	ft_builtin_pwd(t_shell *shl, int *pos)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	(*pos)++;
	if (pwd == NULL)
	{
		ft_perror(PWD_NONEXISTENT_ERROR, NULL, NULL);
		return (ERNUM_PWD_NOTEXIST);
	}
	ft_write_string(pwd);
	ft_write_string("\n");
	ft_null(&pwd);
	while (ft_is_del_or_red(shl->tok[*pos]) == 0)
		(*pos)++;
	return (0);
}
