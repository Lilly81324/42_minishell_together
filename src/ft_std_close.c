/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_std_close.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:56:12 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/05 18:00:00 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Resets standard streams based off std
void	ft_std_close(int *std)
{
	if (std == NULL)
		return ;
	close(std[0]);
	close(std[1]);
	close(std[2]);
}
