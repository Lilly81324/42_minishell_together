/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:03:44 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/04 16:09:24 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_abs_commands(char **arg, int *pos)
{
	int	len;

	len = 0;
	while (ft_is_delimiter(arg[len + (*pos)]) == 0)
		len++;
	printf("absoulte\n");
	(*pos) += len;
	return (-1);
}
