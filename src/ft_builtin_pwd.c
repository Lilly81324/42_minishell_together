/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_pwd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:25:52 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/06 16:55:46 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// imitates behaviour of "pwd"
int	ft_builtin_pwd(char **tokens, int *pos)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	(*pos)++;
	if (pwd == NULL)
	{
		printf(PWD_NONEXISTENT_ERROR);
		return (1);
	}
	printf("%s\n", pwd);
	ft_null(&pwd);
	while (ft_is_del_or_red(tokens[*pos]) == 0)
		(*pos)++;
	return (-1);
}
