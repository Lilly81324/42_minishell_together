/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_echo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 14:46:57 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/28 17:28:10 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Checks wether current token is "-n"
// Returns 1 if yes (and moves to next token)
// Returns 0 if no
static int	ft_handle_n_flag(char *token, int *pos)
{
	if (ft_is_del_or_red(token) == 0)
	{
		if (token[0] == '-' && token[1] == 'n'\
				&& token[2] == '\0')
		{
			(*pos)++;
			return (1);
		}
	}
	return (0);
}

// after the echo token, check for a "-n" flag, then
// print out all the tokens until you hit a delimiter ore redirect
// first check for empty or flag
// second, print first token without space
// then print all the tokens with a space before until delim or redir
// then return -1
int	ft_builtin_echo(char **tokens, int *pos)
{
	int	n_flag;

	n_flag = 0;
	(*pos)++;
	n_flag = ft_handle_n_flag(tokens[*pos], pos);
	if (ft_is_del_or_red(tokens[*pos]) == 0)
	{
		ft_write_string(tokens[*pos]);
		(*pos)++;
	}
	while (ft_is_del_or_red(tokens[*pos]) == 0)
	{
		write(STDOUT_FILENO, " ", sizeof(char));
		ft_write_string(tokens[*pos]);
		(*pos)++;
	}
	if (n_flag == 0)
		printf("\n");
	return (-1);
}
