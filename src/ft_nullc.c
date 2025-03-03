/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nullc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:46:08 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/03 18:07:32 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Are you sure you dont want to use ft_nullb?
// frees and nulls a pointer to a char pointer,
// WITHOUT freeing its contents
// should receive the address of the variable: ft_nullb(&array)
// pointer my be NULL, which will not do anything
void	ft_nullc(char ***ptr)
{
	if (*ptr == NULL)
		return ;
	free(*ptr);
	*ptr = NULL;
}
