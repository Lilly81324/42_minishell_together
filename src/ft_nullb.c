/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nullb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:05:07 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/04 14:52:59 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// frees a 2d array and its contents
// that ends with its last element being null
// should receive the address of the variable: ft_nullb(&array)
// pointer my be NULL, which will not do anything
void	ft_nullb(char ***ptr)
{
	int	i;

	i = -1;
	if (*ptr == NULL)
		return ;
	while ((*ptr)[++i] != NULL)
	{
		free((*ptr)[i]);
		(*ptr)[i] = NULL;
	}
	free(*ptr);
	*ptr = NULL;
}
