/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:56:42 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/24 15:37:53 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

volatile sig_atomic_t	g_signal = 0;

void	handle_sigint(int sig)
{
	g_signal = sig;
	printf("Received SIGINT (Ctrl+C).\n");
}

int	main(int argc, char **argv, char **envp)
{
	char	**new_env;

	(void)argv;
	(void)argc;
	if (argc > 1)
	{
		printf(ARGC_START);
		return (ERNUM_START_ARGC);
	}
	signal(SIGINT, handle_sigint);
	new_env = ft_copy_env(envp);
	ft_initial_shlvl(&new_env);
	return (ft_loop(&new_env));
}

// TODO:
// Signaling
// maybe remove handling of semicolon
// Ctrl+C
// Ctrl+D
// Ctrl+'\'
// tokenization should be run on arguments for regular commands
// Tokens and arguments can be given as <"abc"> but should be used as <abc>
// if we have Signals for stopping current line then maybe we can use status=0
// 	as default
// Cannot redirect specific outputs to files (2>stderr.txt) (2>/dev/null)