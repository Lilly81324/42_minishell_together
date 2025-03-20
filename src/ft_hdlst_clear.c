/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hdlst_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:55:55 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/20 18:12:56 by sikunne          ###   ########.fr       */
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
		path = node->next;
		free (node);
		node = path;
	}
	lst = NULL;
}