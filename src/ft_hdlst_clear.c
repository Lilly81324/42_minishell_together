/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hdlst_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:55:55 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/21 18:34:45 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_hdlst_clear(t_lst *lst)
{
	t_lst	*node;
	t_lst	*path;

	if (lst == NULL)
		return ;
	node = lst;
	while (node != NULL)
	{
		printf("Node with data: %i\ndeleting...\n", node->data);
		if (node->data >= 0)
			close(node->data);
		path = node->next;
		free (node);
		node = path;
	}
	lst = NULL;
}
