/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hdlst_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:12:36 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/20 17:28:44 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Make a new node and return its adress
// Fills the node with <content> and <fd>
// If allocation failed, content is freed, since it would normally be
// freed by ft_lstclear, which wont reach the content if node couldnt be allocated
// and NULL is returned
t_lst	*ft_hdlst_new(int fd)
{
	t_lst	*new;

	new = (t_lst *)malloc(sizeof(t_lst));
	if (new == NULL)
		return (NULL);
	new->data = fd;
	new->next = NULL;
	return (new);
}
