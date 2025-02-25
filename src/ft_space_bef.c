/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space_bef.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:31:39 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/11 17:09:25 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// returns a string consisting of the contents before the
// first occurence of ' ' in the given string
char	*ft_space_bef(char *str)
{
	int		i;
	char	*new_str;

	i = 0;
	if (str == NULL)
		return (NULL);
	while (str[i] != '\0' && str[i] != ' ')
		i++;
	if (i == 0)
		return (NULL);
	new_str = (char *)malloc((i + 1) * sizeof(char));
	i = 0;
	while (str[i] != '\0' && str[i] != ' ')
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
