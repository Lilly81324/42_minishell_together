/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 13:56:04 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/06 23:42:49 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

// #include <limits.h>
// checks for over and underflow by using a long long int
// returns INT_MAX or INT_MIN in those cases, respectively
// for over/underflow handling put
// if (temp > INT_MAX && fac == 1)
// 	return (INT_MAX);
// if (temp > -(INT_MIN) && fac == -1)
// 	return (INT_MIN);
// below temp = (temp * 10)...
// ACTUALLY doesnt do any of that because atoi doesnt
static int	ft_st_limit(const char *nptr, int i, int fac)
{
	long long int	temp;

	temp = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		temp = (temp * 10) + (nptr[i] - '0');
		i++;
	}
	return (temp * fac);
}

// converts string into number, starting at first +, - or number
// handles NULL string by returning 0
int	ft_atoi(const char *nptr)
{
	int	i;
	int	fac;

	i = 0;
	fac = 1;
	if (nptr == NULL)
		return (*(volatile char *)nptr);
	while (nptr[i] == ' ' || nptr[i] == '\n' || nptr[i] == '\t' \
		|| nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			fac = fac * -1;
		i++;
	}
	return (ft_st_limit(nptr, i, fac));
}
