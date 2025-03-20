/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initial_shlvl.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:36:03 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/20 17:54:15 by sikunne          ###   ########.fr       */
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

// Turns initially given value for SHLVL (string <s>) to integer
// returns, based on that integer, the new SHLVL as integer
// May have whitespaces, then may have one plus or minus sign
// Then hast to have digits forming a valid number
// may be followed by whitespaces
// then has to be at end of string
// Any string miconfiguration returns a 1
// A negative <result> returns 0
// Otherwise give back the <result> increased by 1
static int	st_atoi_shlvl(char *s)
{
	int	i;
	int	fac;
	int	result;

	i = 0;
	result = 0;
	ft_skip_spaces(&i, s);
	fac = st_skip_signs(s, &i);
	if (ft_isdigit((int)s[i]) == 0)
		return (1);
	i--;
	while (ft_isdigit((int)s[++i]) != 0)
		result = (result * 10) + (fac * (s[i] - '0'));
	result++;
	ft_skip_spaces(&i, s);
	if (s[i] != '\0')
		return (1);
	if (result < 0)
		return (0);
	else
		return (result);
}

// Sets shlvl of new envp
// to 1 if max_shlvl reached or no SHLVL found
// or increases it by 1
void	ft_initial_shlvl(char ***new_env)
{
	int		shlvl;
	char	*new;
	char	*temp;

	if (ft_get_env(*new_env, "SHLVL") == NULL)
	{
		ft_change_env(new_env, "SHLVL=1");
		return ;
	}
	shlvl = st_atoi_shlvl(ft_get_env(*new_env, "SHLVL"));
	if (shlvl > MAX_SHLVL)
	{
		ft_perror(ERR_SHLVL_MAX, ft_itoa(shlvl), NULL);
		ft_change_env(new_env, "SHLVL=1");
		return ;
	}
	temp = ft_itoa(shlvl);
	new = ft_strjoin("SHLVL=", temp);
	ft_change_env(new_env, new);
	ft_null(&temp);
	ft_null(&new);
}
