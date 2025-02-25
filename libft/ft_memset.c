/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 11:08:25 by sikunne           #+#    #+#             */
/*   Updated: 2024/11/15 15:45:19 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

// fills first n bytes of s with c
void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*cs;

	i = 0;
	if (n == 0)
		return (s);
	cs = (unsigned char *)s;
	while (i < n)
	{
		cs[i] = c;
		i++;
	}
	return (s);
}
