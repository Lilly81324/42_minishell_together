/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_null_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:08:42 by sikunne           #+#    #+#             */
/*   Updated: 2025/04/07 20:38:44 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// frees 1d array of ints
void	ft_null_int(int **ptr)
{
	int	i;

	i = -1;
	if (*ptr == NULL)
		return ;
	while ((*ptr)[++i] != -2)
		ft_b_close(&((*ptr)[i]));
	free(*ptr);
	*ptr = NULL;
}
