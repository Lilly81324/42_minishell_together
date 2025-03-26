/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subst_excode.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:07:34 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/26 17:09:48 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// If not needed returns -1, otherwise:
// replaces the argument at index with exit code, should the format be right
// Reallocates <*str> by cutting at <index> and inserting <shl->exit_code>
int	ft_subst_excode(t_shell *shl, char **str, int index)
{
	char	*new;
	int		value;
	char	*goal;

	if ((*str)[index] != '$')
		return (-1);
	if ((*str)[index + 1] != '?')
		return (-1);
	ft_str_cut(str, index, 2);
	value = shl->exit_code;
	goal = ft_itoa(value);
	new = ft_str_insert(*str, goal, index);
	ft_null(str);
	ft_null(&goal);
	*str = new;
	return (0);
}
