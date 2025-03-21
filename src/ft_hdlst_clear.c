/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hdlst_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:55:55 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/21 19:20:17 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Frees linked list of file descriptors, starting with <lst>
// Closes file descriptors only if they are >= 0
// Sets lst to NULL, though this probably works only locally
void	ft_hdlst_clear(t_lst *lst)
{
	t_lst	*node;
	t_lst	*path;

	if (lst == NULL)
		return ;
	node = lst;
	while (node != NULL)
	{
		if (node->data >= 0)
			close(node->data);
		path = node->next;
		free (node);
		node = path;
	}
	lst = NULL;
}
