/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_shlvl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:52:10 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/17 17:52:10 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Skips index to first character after the '=' or to the end
static void	st_skip_key(char *s, int *i)
{
	while (s[*i] != '\0' && s[*i] != '=')
		(*i)++;
	if (s[*i] == '=')
		(*i)++;
}

// Turns initially given value for SHLVL to integer and returns it
// String may have one plus sign and then has to have a number
// smaller then 2147483648
// no whitespace, no quotes, no minus signs or mulitple plus signs
// no characters after last digit, has to end there 
int	ft_atoi_shlvl(char *s)
{
	int				i;
	unsigned int	result;

	i = 0;
	result = 0;
	st_skip_key(s, &i);
	if (s[i] == '+')
		i++;
	if (ft_isdigit(s[i]) == 0)
	{
		printf("Non number in SHLVL export value found\n");
		return (0);
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		result = (result * 10) + (s[i] - '0');
		if (result > 2147483647)
			return (0);
		i++;
	}
	if (s[i] == '\0')
		return ((int)result);
	return (0);
}
