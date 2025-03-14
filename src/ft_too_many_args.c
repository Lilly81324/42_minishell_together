/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_too_many_args.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:43:13 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/13 16:33:03 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_too_many_args(char *str, int exit)
{
	ft_perror(ARG_MUCH_ERROR, str, NULL);
	return (exit);
}
