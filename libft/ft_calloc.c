/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:18:47 by sikunne           #+#    #+#             */
/*   Updated: 2024/11/16 12:54:19 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

// allocates an array for nmemb enties, each size bytes and nulls it
void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	size_t	sum;
	char	*result;

	i = 0;
	if (nmemb == 0 || size == 0)
		return ((char *)malloc(0));
	if (nmemb > ((size_t) - 1) / size)
		return (NULL);
	sum = nmemb * size;
	result = (char *)malloc(sum);
	if (result == NULL)
		return (NULL);
	while (i < sum)
	{
		result[i] = 0;
		i++;
	}
	return ((void *)result);
}
