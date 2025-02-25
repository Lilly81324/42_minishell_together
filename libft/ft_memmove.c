/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 11:25:48 by sikunne           #+#    #+#             */
/*   Updated: 2024/11/15 15:47:06 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

// copies src bit by bit to dest
// if src overlaps dest on the right, copying goes right to left
// if src overlaps dest on the left, copying goes left to right
// if they are exactly the same then hurray, job done
// returns pointer to start of dest
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*csrc;
	unsigned char	*cdest;
	size_t			i;

	csrc = (unsigned char *)src;
	cdest = (unsigned char *)dest;
	i = 0;
	if (cdest == csrc || n == 0)
		return (dest);
	if (dest > src)
	{
		while (n--)
			cdest[n] = csrc[n];
	}
	if (dest < src)
	{
		while (i < n)
		{
			cdest[i] = csrc[i];
			i++;
		}
	}
	return (dest);
}
