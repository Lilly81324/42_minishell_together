/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_spaces.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:32:26 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/13 17:13:26 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// increases index to next non-'space'-character or \0
void	ft_skip_spaces(int *i, char *str)
{
	while (str[*i] == ' ' || str[*i] == '\n' || str[*i] == '\t' \
		|| str[*i] == '\v' || str[*i] == '\f' || str[*i] == '\r')
		(*i)++;
	return ;
}
