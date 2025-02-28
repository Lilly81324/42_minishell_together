/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_special_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:59:55 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/28 14:58:48 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// runs builtin commands like exit, cd, unset
// returns 0-255 if programm should close with that code
// returns -1 if programm should continue
int	ft_special_cmd(char **tokens, int *pos, char ***envp)
{
	int	i;

	i = 0;
	ft_skip_spaces(&i, tokens[*pos]);
	if (ft_strncmp(&tokens[*pos][i], "exit", 4) == 0)
		return (1000);
	else if (ft_strncmp(&tokens[*pos][i], "env", 3) == 0)
		return (ft_builtin_env(pos, envp));
	else if (ft_strncmp(&tokens[*pos][i], "pwd", 3) == 0)
		return (ft_builtin_pwd(pos));
	else if (ft_strncmp(&tokens[*pos][i], "cd", 2) == 0)
		return (ft_builtin_cd(tokens, pos, envp));
	else if (ft_strncmp(&tokens[*pos][i], "export", 6) == 0)
		return (ft_builtin_export(tokens, pos, envp));
	else if (ft_strncmp(&tokens[*pos][i], "unset", 5) == 0)
		return (ft_builtin_unset(tokens, pos, envp));
	else if (ft_strncmp(&tokens[*pos][i], "echo", 4) == 0)
		return (ft_builtin_echo(tokens, pos));
	(*pos)++;
	return (-1);
}
