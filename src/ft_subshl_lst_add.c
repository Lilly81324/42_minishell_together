/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subshl_lst_add.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:41:28 by sikunne           #+#    #+#             */
/*   Updated: 2025/04/02 17:51:43 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Adds new node at end of <lst> with <cont> and <fd>
// Or sets it as first node if list empty
void	ft_sushl_lstadd(t_sushl *lst, char ***env, int num)
{
	t_sushl	*node;

	node = lst;
	while (node->next != NULL)
		node = node->next;
	node->next = (t_sushl *)malloc(sizeof(t_sushl));
	node = node->next;
	node->env = ft_env_subshell(env);
	node->num = num;
	node->next = NULL;
}

