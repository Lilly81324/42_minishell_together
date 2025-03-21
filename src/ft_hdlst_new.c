/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hdlst_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:12:36 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/20 18:29:38 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Make a new node and return its adress
// Fills the node with <fd>
// if allocation error NULL is returned
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
