/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subst_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:18:56 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/31 16:33:57 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// 0 => dont expand		1 => expand
// Returns 0 if at dollar sign with spacer after or not expandable
// returns 1 if $ and then valid char
static int	st_after_dollar(char *str, int i)
{
	if (ft_find_c(str[i + 1], SPACES) != -1)
		return (0);
	if (str[i + 1] == '\0')
		return (0);
	if (str[i + 1] == '\"')
		return (0);
	if (str[i + 1] == '\'')
		return (0);
	return (1);
}

// returns 0 if no substitution took place or 1 if it did
// uses quot to track which quotes are active currently
// only toggles quotes, if the other one isnt active
// does not do substitution if single quotes active
static int	st_on_char(t_shell *shl, char **str, int *i, int *quot)
{
	if ((*str)[*i] == '\'' && quot[1] == 0)
		quot[0] = !(quot[0]);
	else if ((*str)[*i] == '\"' && quot[0] == 0)
		quot[1] = !(quot[1]);
	if ((*str)[*i] != '$' || quot[0] == 1)
		return (0);
	if (st_after_dollar(*str, *i) == 0)
		return (0);
	(*i)--;
	if (ft_subst_excode(shl, str, (*i) + 1) == 0)
		return (1);
	if (ft_subst_pid(str, (*i) + 1) == 0)
		return (1);
	ft_subst_reg(*shl->env, str, (*i) + 1);
	return (1);
}

// Substitutes Variables in the <*str> with the repsective values
// from <*shl->envp> by reallocating the string <*str>
void	ft_subst_string(t_shell *shl, char **str)
{
	int		i;
	int		loops;
	int		changes;
	int		quot[2];

	if (str == NULL || *str == NULL)
		return ;
	loops = 0;
	while (loops < MAX_SUBSTITUTIONS)
	{
		i = -1;
		changes = 0;
		quot[0] = 0;
		quot[1] = 0;
		while ((*str)[++i] != '\0')
			changes += st_on_char(shl, str, &i, quot);
		if ((*str)[i] == '\0' && changes == 0)
			break ;
		loops++;
	}
}
