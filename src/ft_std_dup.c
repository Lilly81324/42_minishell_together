/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_std_dup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:46:04 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/05 18:01:05 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Duplicates the current standard streams into <std>
void	ft_std_dup(int *std)
{
	std[0] = dup(STDIN_FILENO);
	std[1] = dup(STDOUT_FILENO);
	std[2] = dup(STDERR_FILENO);
}
