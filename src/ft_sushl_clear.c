/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sushl_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:56:45 by sikunne           #+#    #+#             */
/*   Updated: 2025/04/02 17:59:00 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Frees linked list of subshells, starting with <lst>
// Sets lst to NULL, though this probably works only locally
void	ft_sushl_clear(t_sushl *lst)
{
	t_sushl	*node;
	t_sushl	*path;

	if (lst == NULL)
		return ;
	node = lst;
	while (node != NULL)
	{
		ft_nullb(node->env);
		path = node->next;
		free (node);
		node = path;
	}
	lst = NULL;
}
