/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_special.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:08:21 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/28 16:53:23 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// returns 1 if the text in <hay> starting at <pos>
// is equal to the <len> characters of <needle>
static int	ft_text_check(char *hay, const char *needle, int len, int pos)
{
	if (ft_strncmp(&hay[pos], needle, len) == 0)
	{
		pos += len;
		ft_skip_spaces(&pos, hay);
		if (hay[pos] == '\0')
			return (1);
	}
	return (0);
}

// returns 1 if special command or 0 if regular
int	ft_check_special(char *inp)
{
	int	i;

	i = 0;
	ft_skip_spaces(&i, inp);
	if (ft_text_check(inp, "exit", 4, i) == 1)
		return (1);
	else if (ft_text_check(inp, "env", 3, i) == 1)
		return (1);
	else if (ft_text_check(inp, "pwd", 3, i) == 1)
		return (1);
	else if (ft_text_check(inp, "cd", 2, i) == 1)
		return (1);
	else if (ft_text_check(inp, "export", 6, i) == 1)
		return (1);
	else if (ft_text_check(inp, "unset", 5, i) == 1)
		return (1);
	else if (ft_text_check(inp, "echo", 4, i) == 1)
		return (1);
	else if (ft_text_check(inp, "history", 7, i) == 1)
		return (1);
	return (0);
}
