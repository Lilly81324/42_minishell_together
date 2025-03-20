/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hdlst_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:13:33 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/20 18:29:53 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Adds new node at end of <lst> with <cont> and <fd>
// Or sets it as first node if list empty
void	ft_hdlst_add(t_lst **lst, int fd)
{
	t_lst	*node;

	if (*lst == NULL)
	{
		*lst = ft_hdlst_new(fd);
		return ;
	}
	node = *lst;
	while (node->next != NULL)
		node = node->next;
	node->next = ft_hdlst_new(fd);
}
