/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:56:42 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/28 15:59:59 by sikunne          ###   ########.fr       */
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
// Add history builtin?
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
