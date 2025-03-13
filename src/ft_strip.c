/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strip.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 17:30:12 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/07 18:28:03 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Returns the index of the first character in "core"
// that is not in "extra"
// if no character found, returns index of \0
static int	st_get_start(char *extra, char *core)
{
	int	i;

	i = 0;
	while (ft_find_c(core[i], extra) != -1)
		i++;
	return (i);
}

// Gives back index of last character in string "core"
// that is not in "extra"
// if no character found, returns 0
static int	st_get_end(char *extra, char *core)
{
	int	i;

	i = 0;
	while (core[i] != '\0')
		i++;
	if (i > 0)
		i--;
	while (ft_find_c(core[i], extra) != -1)
		i--;
	return (i);
}

// Removes the first and last occurences of any "extra" characters
// from core and ALLOCATES a new copy that is returned
// if no string left, empty string or any argument is NULL, returns NULL
char	*ft_strip(char *extra, char *core)
{
	int		start;
	int		end;
	char	*result;

	if (core == NULL || extra == NULL)
		return (NULL);
	start = st_get_start(extra, core);
	end = st_get_end(extra, core);
	if (end < start || core[start] == '\0')
		return (NULL);
	result = (char *)malloc((end - start + 2) * sizeof(char));
	result[end - start + 1] = '\0';
	end++;
	while (--end >= start)
		result[end - start] = core[end];
	return (result);
}
