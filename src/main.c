/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:56:42 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/07 17:13:22 by sikunne          ###   ########.fr       */
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
// Signaling
// Exit Codes
// maybe remove handling of semicolon
// <<
// PATH Argument substitution
// Exit code substitution
// Ctrl+C
// Ctrl+D
// Ctrl+'\'
// tokenization should be run on arguments for regular commands
// quotes are wrongy included in the output of some things, such as echo
// Commands can somehow still be executed even if PATH is gone
// Figure out why commands can still be executed with path gone
// make "export " print out alphabetically