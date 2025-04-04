/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sig_term.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:51:57 by sikunne           #+#    #+#             */
/*   Updated: 2025/04/04 13:41:54 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Returns 1 if given string is NULL
int	ft_sig_term(char *input)
{
	if (input != NULL)
		return (0);
	if (isatty(STDIN_FILENO) == 1)
		ft_perror("exit\n", NULL, NULL);
	return (1);
}
