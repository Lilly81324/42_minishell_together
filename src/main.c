/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:56:42 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/12 19:42:04 by sikunne          ###   ########.fr       */
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
// Exit Codes by using struct everywhere, and setting value in waitpid
// maybe remove handling of semicolon
// <<
// Exit code substitution
// Ctrl+C
// Ctrl+D
// Ctrl+'\'
// tokenization should be run on arguments for regular commands
// quotes are wrongy included in the output of some things, such as echo
// make "export " print out alphabetically
// SHLVL cannot be exported to non-number -> 0 instead
// SHLVL is always 1 smaller than given in export
// Tokens and arguments can be given as <"abc"> but should be used as <abc>
// if we have Signals for stopping current line then maybe we can use status=0
// 	as default
// Errors should be printed in stderr isntead of stdout