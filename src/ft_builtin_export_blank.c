/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_export_blank.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:38:45 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/14 19:25:35 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// For printing each string in ft_blank_export
static void	st_print_key(char *str)
{
	int	i;

	i = -1;
	ft_write_string("declare -x ");
	while (str[++i] != '=')
		write(STDOUT_FILENO, &(str[i]), sizeof(char));
	ft_write_string("=\"");
	while (str[++i] != '\0')
		write(STDOUT_FILENO, &(str[i]), sizeof(char));
	ft_write_string("\"\n");
}

// returns str1[x] - str2[x] at first diverging character
// is negative if str1 is smaller then str2
static int	st_str_cmp(char *str1, char *str2)
{
	int	i;

	i = -1;
	while (str1[++i] != '\0' && str1[i] != '=')
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
	}
	return (str1[i] - str2[i]);
}

// Gives back index of string that is bigger then <envp[smal_ind]>
// and is also the smallest of those
// or -1 if no bigger string was found (small_ind is biggest string)
static int	st_next_index(char **envp, int smal_ind)
{
	int	cur_ind;
	int	next_ind;

	cur_ind = -1;
	next_ind = -1;
	while (envp[++cur_ind] != NULL)
	{
		if (st_str_cmp(envp[cur_ind], envp[smal_ind]) <= 0)
			continue ;
		if (next_ind == -1 || st_str_cmp(envp[cur_ind], envp[next_ind]) < 0)
			next_ind = cur_ind;
	}
	return (next_ind);
}

// Find smallest possible ascii string
// Print it
// Find smallest possible ascii string, that is bigger than current
// Print that
// When no bigger string then END
void	ft_builtin_export_blank(char **envp)
{
	int	cur_ind;
	int	smal_ind;

	cur_ind = -1;
	smal_ind = 0;
	while (envp[++cur_ind] != NULL)
	{
		if (st_str_cmp(envp[cur_ind], envp[smal_ind]) < 0)
			smal_ind = cur_ind;
	}
	st_print_key(envp[smal_ind]);
	while (smal_ind != -1)
	{
		smal_ind = st_next_index(envp, smal_ind);
		if (smal_ind != -1 && \
			!(envp[smal_ind][0] == '_' && envp[smal_ind][1] == '='))
			st_print_key(envp[smal_ind]);
	}
}
