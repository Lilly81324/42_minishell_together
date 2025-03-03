/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:56:42 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/03 18:00:06 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char	**new_env;

	(void)argv;
	(void)argc;
	new_env = ft_copy_env(envp);
	return (ft_loop(&new_env));
}

// TODO:
// Launching commands with relative/absolute paths
// Signaling
// Exit Codes
// maybe remove handling of semicolon
// <<
// Argument substitution
// Argument declaration
// Ctrl+C
// Ctrl+D
// Ctrl+'\'
// autocomplete of commands
// cd builtin in itself should go to HOME

// Issues:	Commands can be chained together too easily:
//				history cd .. ls -> should probably only run 1 command
//			Commands can somehow still be executed even if PATH is gone
