/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:56:42 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/17 18:33:57 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char	**new_env;

	(void)argv;
	(void)argc;
	new_env = ft_copy_env(envp);
	if (ft_get_env(new_env, "SHLVL") == NULL)
		ft_change_env(&new_env, "SHLVL=0");
	else
		ft_env_increase(&new_env, "SHLVL", 1);
	return (ft_loop(&new_env));
}

// TODO:
// Signaling
// maybe remove handling of semicolon
// <<
// Ctrl+C
// Ctrl+D
// Ctrl+'\'
// tokenization should be run on arguments for regular commands
// quotes are wrongy included in the output of some things, such as echo
// school bash exports SHLVL to a vlaue always one smaller, ours doesnt
// Tokens and arguments can be given as <"abc"> but should be used as <abc>
// if we have Signals for stopping current line then maybe we can use status=0
// 	as default
// Cannot redirect specific outputs to files (2>stderr.txt) (2>/dev/null)