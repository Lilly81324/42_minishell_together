/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_std_reset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:47:59 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/05 18:02:43 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Resets standard streams based off std
void	ft_std_reset(int *std)
{
	if (std == NULL)
		return ;
	dup2(std[0], STDIN_FILENO);
	dup2(std[1], STDOUT_FILENO);
	dup2(std[2], STDERR_FILENO);
}
