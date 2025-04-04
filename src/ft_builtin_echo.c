/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_echo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 14:46:57 by sikunne           #+#    #+#             */
/*   Updated: 2025/04/04 15:51:47 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Checks wether current token is "-n"
// Returns 1 if yes (and moves to next token)
// Returns 0 if no
static int	ft_handle_n_flag(char *token, int *pos)
{
	int	i;

	i = 1;
	if (ft_is_del_or_red(token) == 0)
	{
		if (token[0] != '-')
			return (0);
		while (token[i] == 'n')
			i++;
		if (token[i] == '\0' && token[i - 1] == 'n')
		{
			(*pos)++;
			return (1);
		}
	}
	return (0);
}

// Echoes the arguments after <tok[pos]>
// unless they are a redirector
// moves until delimiter
static void	st_echo_args(char **tok, int *pos)
{
	int	first;

	first = 1;
	while (ft_is_delimiter(tok[*pos]) == 0)
	{
		ft_skip_redirector(tok, pos);
		if (ft_is_del_or_red(tok[*pos]) == 0)
		{
			if (first == 1)
				first = 0;
			else
				write(STDOUT_FILENO, " ", sizeof(char));
			ft_write_string(tok[*pos]);
			(*pos)++;
		}
	}
}

// after the echo token, check for a "-n" flag, then
// print out all the tokens until you hit a delimiter ore redirect
// first check for empty or flag
// second, print first token without space
// then print all the tokens with a space before until delim or redir
// then return -1
int	ft_builtin_echo(t_shell *shl, int *pos)
{
	int	n_flag;

	n_flag = 0;
	(*pos)++;
	ft_skip_redirector(shl->tok, pos);
	n_flag = ft_handle_n_flag(shl->tok[*pos], pos);
	st_echo_args(shl->tok, pos);
	if (n_flag == 0)
		ft_write_string("\n");
	return (0);
}
