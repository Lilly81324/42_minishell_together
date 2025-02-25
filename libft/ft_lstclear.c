/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:40:50 by sikunne           #+#    #+#             */
/*   Updated: 2024/11/16 16:00:39 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;
	t_list	*path;

	if (*lst == NULL)
		return ;
	node = *lst;
	while (node != NULL)
	{
		(*del)(node->content);
		path = node->next;
		free (node);
		node = path;
	}
	*lst = NULL;
}
