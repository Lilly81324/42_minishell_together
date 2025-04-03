/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_history.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 16:56:38 by sikunne           #+#    #+#             */
/*   Updated: 2025/04/04 00:46:25 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Print out history of inputs
int	ft_builtin_history(t_shell *shl, int *pos)
{
	HIST_ENTRY	**hist;
	int			i;

	if (ft_is_del_or_red(shl->tok[(*pos) + 1]) == 0)
		return (ft_too_many_args("history", ERNUM_HISTORY_ARGC));
	hist = history_list();
	i = -1;
	if (hist == NULL)
		return (0);
	while (hist[++i] != NULL)
	{
		ft_write_string("  ");
		ft_putnbr_fd(i + 1, STDOUT_FILENO);
		ft_write_string("  ");
		ft_write_string(hist[i]->line);
		ft_write_string("\n");
	}
	(*pos)++;
	return (0);
}
