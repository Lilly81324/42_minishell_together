/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_null.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:53:26 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/20 14:58:18 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// frees and nulls a pointer
// technically it only sets the local copy to NULL
// meaning the original pointer still points to the memory
// in the future, pass the address of the pointer, 
// so the actual *pointer can be = NULL
void	ft_null(void *ptr)
{
	if (ptr != NULL)
	{
		free(ptr);
		ptr = NULL;
	}
}
