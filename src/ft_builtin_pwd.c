/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_pwd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:25:52 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/13 17:09:36 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// imitates behaviour of "pwd"
int	ft_builtin_pwd(t_shell *shl, int *pos)
{
	char	*pwd;

	shl->exit_code = 0;
	pwd = getcwd(NULL, 0);
	(*pos)++;
	if (pwd == NULL)
	{
		ft_perror(PWD_NONEXISTENT_ERROR, NULL, NULL);
		shl->exit_code = ERNUM_PWD_NOTEXIST;
		return (0);
	}
	printf("%s\n", pwd);
	ft_null(&pwd);
	while (ft_is_del_or_red(shl->tok[*pos]) == 0)
		(*pos)++;
	return (0);
}
