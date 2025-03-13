/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_substitution.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:18:56 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/13 16:29:35 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Toggles <x> between 0 and 1
static void	st_toggle(int *x)
{
	if (*x == 0)
		*x = 1;
	else
		*x = 0;
}

// replaces the argument at index with exit code, should the format be right
// Reallocates <*str> by cutting at <index> and inserting <shl->exit_code>
static int	st_exit_code_subst(t_shell *shl, char **str, int index)
{
	char	*new;
	int		value;
	char	*goal;

	if ((*str)[index] != '$')
		return (-1);
	if ((*str)[index + 1] != '?')
		return (-1);
	ft_str_cut(str, index, 2);
	value = shl->exit_code;
	goal = ft_itoa(value);
	new = ft_str_insert(*str, goal, index);
	ft_null(str);
	ft_null(&goal);
	*str = new;
	return (0);
}

// Replaces string <*str> with one where an argument is insterted
// "This is pwd:$PWD" -> "This is pwd:/home/sikunne"
// counts how long the Argument Name is (ends at \0 or ![a-z,A-Z,0-9,_])
// Creates a key consisting of that Argument without '$' to get the value
// Then cuts out that key with '$' from the string 
// If value was found for key then insert it by reallocation
static void	st_substitution(char **env, char **str, int index)
{
	int		len;
	char	*key;
	char	*value;
	char	*temp;

	len = 0;
	while ((*str)[index + len + 1] != '\0' && \
			(ft_isalnum((*str)[index + len + 1]) != 0 || \
			(*str)[index + len + 1] == '_'))
		len++;
	key = (char *)malloc((len + 1) * sizeof(char));
	ft_strlcpy(key, &((*str)[index + 1]), len + 1);
	value = ft_get_env(env, key);
	ft_str_cut(str, index, len + 1);
	if (value != NULL)
	{
		temp = ft_str_insert((*str), value, index);
		free(*str);
		(*str) = temp;
	}
	ft_null(&key);
}

// Substitutes Variables in the <*str> with the repsective values
// from <*shl->envp> by reallocating the string <*str>
void	ft_string_substitution(t_shell *shl, char **str)
{
	int	i;
	int	loops;
	int	quoted;

	if (str == NULL || *str == NULL)
		return ;
	quoted = 0;
	loops = 0;
	while (loops < MAX_SUBSTITUTIONS)
	{
		i = -1;
		while ((*str)[++i] != '\0')
		{
			if ((*str)[i] == '\'')
				st_toggle(&quoted);
			if (st_exit_code_subst(shl, str, i) == 0)
				continue;
			if ((*str)[i] == '$' && quoted == 0)
				st_substitution(*shl->env, str, i);
		}
		loops++;
	}
}
