/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sig_term.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:51:57 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/25 18:53:07 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Returns 1 if given string is NULL
int	ft_sig_term(char *input)
{
	if (input != NULL)
		return (0);
	printf("exit\n");
	return (1);
}
