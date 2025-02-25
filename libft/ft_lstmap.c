/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:02:27 by sikunne           #+#    #+#             */
/*   Updated: 2024/11/16 16:40:57 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*node;
	t_list	*result;
	void	*new_content;

	if (lst == NULL || f == NULL)
		return (NULL);
	newlist = NULL;
	node = lst;
	while (node != NULL)
	{
		new_content = (*f)(node->content);
		result = ft_lstnew(new_content);
		if (result == NULL)
		{
			del(new_content);
			ft_lstclear(&newlist, del);
			return (NULL);
		}
		ft_lstadd_back(&newlist, result);
		node = node->next;
	}
	return (newlist);
}
