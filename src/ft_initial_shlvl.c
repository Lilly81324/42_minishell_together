/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initial_shlvl.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:36:03 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/18 19:31:19 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Skips past + or - sign and returns factor of the number
// returns -1 if s[*i] = '-'
// else returns 1
static int	st_skip_signs(char *s, int *i)
{
	int	fac;

	fac = 1;
	if (s[*i] == '+' || s[*i] == '-')
	{
		if (s[*i] == '-')
			fac = -1;
		(*i)++;
	}
	return (fac);
}

// Turns initially given value for SHLVL to integer and returns it
// String may have one plus sign and then has to have a number
// smaller then 2147483648
// may have whitespaces before the sign/earliest number
// and may have whitespaces after the last number, but no more other chars
static int	st_atoi_shlvl(char *s)
{
	int				i;
	int				fac;
	unsigned int	result;

	i = 0;
	result = 0;
	ft_skip_spaces(&i, s);
	fac = st_skip_signs(s, &i);
	if (ft_isdigit((int)s[i]) == 0)
		return (0);
	while (ft_isdigit((int)s[i]) != 0)
	{
		result = (result * 10) + (s[i] - '0');
		i++;
	}
	ft_skip_spaces(&i, s);
	if (s[i] != '\0')
		return (0);
	if (result < 0)
		return (-1);
	if (result >= 0 && fac == 1)
		return ((int)result);
	if (fac != 1)
		return (-1);
	return (0);
}


// Sets shlvl of new envp
// to 1 if max_shlvl reached or no SHLVL found
// or increases it by 1
void	ft_initial_shlvl(char ***new_env)
{
	int	shlvl;

	if (ft_get_env(*new_env, "SHLVL") == NULL)
	{
		ft_change_env(new_env, "SHLVL=1");
		return ;
	}
	shlvl = st_atoi_shlvl(ft_get_env(*new_env, "SHLVL"));
	printf("Current shlvl is %i\n", shlvl);
	if (shlvl > MAX_SHLVL - 1)
	{
		printf("Final SHLVL=%i\n", 1);
		ft_perror(ERR_SHLVL_MAX, ft_itoa(shlvl), NULL);
		ft_change_env(new_env, "SHLVL=1");
		return ;
	}
	printf("Final SHLVL=%i\n", shlvl + 1);
	ft_env_increase(new_env, "SHLVL", 1);
}
