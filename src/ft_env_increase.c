/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_increase.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:19:35 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/11 18:10:58 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Specialized atoi that works only for positive numbers
// with at most one plus sign in front of the number
// and nothing after the number
// !!! has no overflow protection
static int	st_atoi(const char *nptr)
{
	int	i;
	int	res;

	res = 0;
	i = 0;
	if (nptr == NULL)
		return (-1);
	while (nptr[i] == ' ' || nptr[i] == '\n' || nptr[i] == '\t' \
		|| nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r')
		i++;
	if (nptr[i] == '+')
		i++;
	if (!(nptr[i] >= '0' && nptr[i] <= '9'))
		return (-1);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = (res * 10) + (nptr[i] - '0');
		i++;
	}
	if (nptr[i] != '\0')
		return (-1);
	return (res);
}

// Increases the value of enviroment variable <target> by <value>
// or sets it to "<target>=0" if not valid custom atoi value
// uses custom atoi with rules as seen in function above
void	ft_env_increase(char ***envp, char *target, int value)
{
	int		current;
	char	*new;
	char	*temp;
	char	*result;

	current = st_atoi(ft_get_env(*envp, target));
	if (current == -1)
	{
		new = ft_str_add(target, "=0");
		ft_change_env(envp, new);
		ft_null(&new);
		return ;
	}
	current += value;
	new = ft_itoa(current);
	temp = ft_str_add(target, "=");
	result = ft_str_add(temp, new);
	ft_change_env(envp, result);
	ft_null(&new);
	ft_null(&temp);
	ft_null(&result);
	return ;
}
