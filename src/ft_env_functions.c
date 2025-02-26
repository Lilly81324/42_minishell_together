/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:58:16 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/26 17:09:49 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Adds key-value-pair to envp
// Reassigns the entire <ptr> so that it contains <pair>
static void	ft_add_to_env(char ***ptr, char *pair)
{
	int		len;
	char	**new;

	len = 0;
	while ((*ptr)[len] != NULL)
		len++;
	new = (char **)malloc((len + 2) * sizeof(char *));
	new[len + 1] = NULL;
	new[len] = ft_strdup(pair);
	while (--len >= 0)
		new[len] = ft_strdup((*ptr)[len]);
	ft_nullb(*ptr);
	*ptr = new;
}

// Searches the key from <pair> in <*envp> and replaces it with <pair>
// Or adds it at the end of <*envp> by reassingement
void	ft_change_env(char ***envp, char *pair)
{
	int		pos;
	char	*new;

	pos = 0;
	while ((*envp)[pos] != NULL)
	{
		if (ft_strncmp((*envp)[pos], pair, ft_find_c('=', pair) + 1) == 0)
			break ;
		pos++;
	}
	if ((*envp)[pos] == NULL)
	{
		ft_add_to_env(envp, pair);
		return ;
	}
	free((*envp)[pos]);
	new = ft_strdup(pair);
	(*envp)[pos] = new;
	return ;
}

// returns string that starts with <key> in <envp>
// or NULL if not found
char	*ft_get_env(char **envp, char *key)
{
	int	i;

	i = -1;
	while (envp[++i] != NULL)
	{
		if (ft_strncmp(envp[i], key, ft_strlen(key)) == 0)
		{
			if (envp[i][ft_strlen(key)] == '=')
				return (envp[i]);
		}
	}
	return (NULL);
}

// Removes the key string from evp by reassignement
void	ft_remove_env(char ***envp, char *key)
{
	int		len;
	int		i;
	char	**new;

	len = 0;
	while ((*envp)[len] != NULL)
		len++;
	new = (char **)malloc((len) * sizeof(char *));
	new[len - 1] = NULL;
	i = -1;
	while (ft_strncmp((*envp)[++i], key, ft_strlen(key)) != 0)
		new[i] = ft_strdup((*envp)[i]);
	while ((*envp)[i + 1] != NULL)
	{
		new[i] = ft_strdup((*envp)[i + 1]);
		i++;
	}
	ft_nullb(*envp);
	*envp = new;
}

// creates a deep copy of the contents of the given char**
// returns that copy
char	**ft_copy_env(char **envp)
{
	int		len;
	char	**res;

	len = 0;
	if (envp == NULL)
		return (NULL);
	while (envp[len] != NULL)
		len++;
	res = (char **)malloc((len + 1) * sizeof(char *));
	res[len] = NULL;
	while (--len >= 0)
		res[len] = ft_strdup(envp[len]);
	return (res);
}
