/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subst_reg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:14:11 by sikunne           #+#    #+#             */
/*   Updated: 2025/04/09 13:59:43 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Replaces string <*str> with one where an argument is insterted
// "This is pwd:$PWD" -> "This is pwd:/home/sikunne"
// counts how long the Argument Name is (ends at \0 or ![a-z,A-Z,0-9,_])
// Creates a key consisting of that Argument without '$' to get the value
// Then cuts out that key with '$' from the string 
// If value was found for key then insert it by reallocation
void	ft_subst_reg(char **env, char **str, int index)
{
	int		len;
	char	*key;
	char	*value;
	char	*temp;

	len = 0;
	while ((*str)[index + len + 1] != '\0' && \
(ft_isalnum((*str)[index + len + 1]) != 0 || \
(*str)[index + len + 1] == '_'))
		len++;
	key = (char *)malloc((len + 1) * sizeof(char));
	ft_strlcpy(key, &((*str)[index + 1]), len + 1);
	value = ft_get_env(env, key);
	ft_str_cut(str, index, len + 1);
	if (value != NULL)
	{
		temp = ft_str_insert((*str), value, index);
		free(*str);
		(*str) = temp;
	}
	ft_null(&key);
}
