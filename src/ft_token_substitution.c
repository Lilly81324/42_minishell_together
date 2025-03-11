/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_substitution.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:18:56 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/11 16:40:15 by sikunne          ###   ########.fr       */
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

//echo "lel $PWD lol"
// replace string <*tok[pos] with one where the current argument is insterted
static void	st_substitution(char ***env, char ***tok, int pos, int index)
{
	int		len;
	char	*key;
	char	*value;
	char	*temp;

	len = 0;
	while ((*tok)[pos][index + len] != '\0' && \
		ft_find_c((*tok)[pos][index + len], SPACES) == -1)
		len++;
	len--;
	key = (char *)malloc((len + 1) * sizeof(char));
	ft_strlcpy(key, &((*tok)[pos][index + 1]), len + 1);
	value = ft_get_env(*env, key);
	ft_str_cut(&((*tok)[pos]), index, len + 1);
	temp = ft_str_insert((*tok)[pos], value, index);
	free((*tok)[pos]);
	(*tok)[pos] = temp;
	ft_null(&key);
}

// replaces "abc $ARG" to "abc value"
void	ft_token_substitution(char ***env, char ***tok)
{
	int	i;
	int	j;
	int	quoted;

	if (*tok == NULL || (*tok)[0] == NULL)
		return ;
	i = -1;
	while ((*tok)[++i] != NULL)
	{
		j = -1;
		quoted = 0;
		while ((*tok)[i][++j] != '\0')
		{
			if ((*tok)[i][j] == '\'')
				st_toggle(&quoted);
			if ((*tok)[i][j] == '$' && quoted == 0)
				st_substitution(env, tok, i, j);
		}
	}
}