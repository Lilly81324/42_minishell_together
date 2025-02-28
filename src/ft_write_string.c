/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 17:26:50 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/28 17:27:33 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Writes given string to stdout
void	ft_write_string(char *string)
{
	int	i;

	i = -1;
	if (string == NULL)
		return ;
	while (string[++i] != '\0')
		write(STDOUT_FILENO, &string[i], sizeof(char));
}
