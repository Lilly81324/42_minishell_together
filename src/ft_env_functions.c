/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:58:16 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/18 16:49:40 by sikunne          ###   ########.fr       */
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
	ft_nullb(ptr);
	*ptr = new;
}

// Searches the key from <pair> in <*envp> and replaces it with <pair>
// Or adds it at the end of <*envp> by reassingement and allocating new copy
void	ft_change_env(char ***envp, char *pair)
{
	int		pos;

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
	(*envp)[pos] = ft_strdup(pair);
	return ;
}

// returns string that starts with <key> in <envp>
// does NOT allocate on heap, only gives back reference
// or NULL if not found
char	*ft_get_env(char **envp, char *key)
{
	int	i;
	int	key_len;

	key_len = ft_strlen(key);
	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], key, key_len) == 0)
		{
			if (envp[i][key_len] == '=')
				return (envp[i] + key_len + 1);
		}
		i++;
	}
	return (NULL);
}

// Removes the key string from evp by reassignement
// May only be called if you know for certain that the key to remove exists
// so it may never be called for an empty envp
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
	while ((*envp)[++i] != NULL)
	{
		if (ft_strncmp((*envp)[i], key, ft_strlen(key)) == 0 && \
			(*envp)[i][ft_strlen(key)] == '=')
			break ;
		new[i] = ft_strdup((*envp)[i]);
	}
	while ((*envp)[++i] != NULL)
		new[i - 1] = ft_strdup((*envp)[i]);
	ft_nullb(envp);
	*envp = new;
}

// creates a deep copy of the contents of the given char**
// returns that copy
char	**ft_copy_env(char **envp)
{
	int		len;
	char	**res;

	len = 0;
	if (envp != NULL)
	{
		while (envp[len] != NULL)
			len++;
	}
	res = (char **)malloc((len + 1) * sizeof(char *));
	res[len] = NULL;
	while (--len >= 0)
		res[len] = ft_strdup(envp[len]);
	return (res);
}
