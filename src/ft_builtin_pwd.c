/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_pwd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:25:52 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/03 18:10:55 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// imitates behaviour of "pwd"
int	ft_builtin_pwd(int *pos)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	(*pos)++;
	if (pwd == NULL)
	{
		printf(PWD_NONEXISTENT_ERROR);
		return (1000);
	}
	printf("%s\n", pwd);
	ft_null(&pwd);
	return (-1);
}
