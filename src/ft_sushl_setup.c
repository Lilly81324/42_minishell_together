/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sushl_setup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:38:31 by sikunne           #+#    #+#             */
/*   Updated: 2025/04/02 23:17:02 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_sushl	*ft_sushls_setup(t_shell *shl)
{
	int		count;
	int		i;
	t_sushl	*sub;

	count = 0;
	i = -1;
	while (shl->tok[++i] != NULL)
	{
		if (ft_strcmp(shl->tok[i], "|") == 0)
			count++;
	}
	printf("%i+1 chunks found, based on pipes\n", count);
	sub = (t_sushl *)malloc(sizeof(t_sushl));
	if (sub == NULL)
		return (NULL);
	sub->env = &ft_env_subshell(shl->env);
	sub->num = 0;
	sub->next = NULL;
	i = 0;
	while (++i < count + 1)
	{
		printf("Making node %i\n", i);
		ft_sushl_lstadd(sub, shl->env, i);
	}
	return (sub);
}
