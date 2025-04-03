/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nulld.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:58:23 by sikunne           #+#    #+#             */
/*   Updated: 2025/04/03 18:20:34 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Frees a 3d array and its contents
// that ends with its last element being null
// should receive the address of the variable: ft_nulld(&array)
// pointer my be NULL, which will not do anything
void	ft_nulld(char ****ptr)
{
	int i;
	int	j;

	if (*ptr == NULL)
		return ;
	i = -1;
	while ((*ptr)[++i] != NULL)	
	{
		j = -1;
		while ((*ptr)[i][++j])
		{
			free((*ptr)[i][j]);
			(*ptr)[i][j] = NULL;
		}
		free((*ptr)[i]);
		(*ptr)[i] = NULL;
	}
	free(*ptr);
	(*ptr) = NULL;
}
