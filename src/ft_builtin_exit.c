/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:00:34 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/06 18:16:41 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
// first part of atoi that skips to the number
// returns factor for final atoi number
static int	st_skip_for_atoi(char *nptr, int *i)
{
	int	fac;

	fac = 1;
	while (nptr[*i] == ' ' || nptr[*i] == '\n' || nptr[*i] == '\t' \
		|| nptr[*i] == '\v' || nptr[*i] == '\f' || nptr[*i] == '\r')
		(*i)++;
	if (nptr[*i] == '-' || nptr[*i] == '+')
	{
		if (nptr[*i] == '-')
			fac = fac * -1;
		(*i)++;
	}
	return (fac);
}

// Special Atoi for exit codes
// turns string into number % 256
static int	st_exit_atoi(char *nptr)
{
	int				i;
	int				fac;
	long long int	number;

	i = 0;
	number = 0;
	fac = st_skip_for_atoi(nptr, &i);
	if (!(nptr[i] >= '0' && nptr[i] <= '9'))
		return (-1);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		number = (number * 10) + (nptr[i] - '0');
		i++;
	}
	if (fac < 1)
		return (((number * fac) % 256 + 256) % 256);
	return ((number * fac) % 256);
}

// builtin for the exit function
// no arguments -> exits with 0
// numeric argument -> exits with x%256
// nonnumeric argument -> error, exits with 2
// too many arguments -> error, too many args exits with 1
int	ft_builtin_exit(char **tokens, int *pos)
{
	int	status;

	(*pos)++;
	if (tokens[*pos] == NULL)
	{
		printf("exit\n");
		return (1000);
	}
	status = st_exit_atoi(tokens[*pos]);
	if (status < 0)
	{
		printf("exit\n");
		printf(EXIT_NUMERIC_ERROR, tokens[*pos]);
		return (1002);
	}
	if (tokens[(*pos) + 1] == NULL)
	{
		printf("exit\n");
		return (status + 1000);
	}
	printf("exit\n");
	ft_too_many_args("exit");
	return (1001);
}
