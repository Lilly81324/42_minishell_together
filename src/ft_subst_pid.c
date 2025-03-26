/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subst_pid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:10:20 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/26 17:10:55 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// If not needed returns -1, otherwise:
// replaces the argument at index with exit code, should the format be right
// Reallocates <*str> by cutting at <index> and inserting <shl->exit_code>
int	ft_subst_pid(char **str, int index)
{
	char	*new;
	char	*pid;

	if ((*str)[index] != '$')
		return (-1);
	if ((*str)[index + 1] != '$')
		return (-1);
	ft_str_cut(str, index, 2);
	pid = ft_get_pid_str();
	if (pid == NULL)
		return (0);
	new = ft_str_insert(*str, pid, index);
	ft_null(str);
	ft_null(&pid);
	*str = new;
	return (0);
}
