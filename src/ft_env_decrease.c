/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_decrease.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:24:18 by sikunne           #+#    #+#             */
/*   Updated: 2025/04/02 16:24:24 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Decreases the value of enviroment variable <target> by <value>
// or sets it to "<target>=0" if not valid custom atoi value
// uses custom atoi with rules as seen in function above
// If targets initial value is 0 or inital value - <value> is
// less then 0, then set "<target>=0"
void	ft_env_decrease(char ***envp, char *target, int value)
{
	int		current;
	char	*new;
	char	*temp;
	char	*result;

	current = st_atoi(ft_get_env(*envp, target));
	if (current == -1 || current - value < 0)
	{
		new = ft_strjoin(target, "=0");
		ft_change_env(envp, new);
		ft_null(&new);
		return ;
	}
	current -= value;
	new = ft_itoa(current);
	temp = ft_strjoin(target, "=");
	result = ft_strjoin(temp, new);
	ft_change_env(envp, result);
	ft_null(&new);
	ft_null(&temp);
	ft_null(&result);
	return ;
}
