/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:56:42 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/19 17:37:05 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_sigint(int sig)
{
	(void)sig;
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
// <<
// Ctrl+C
// Ctrl+D
// Ctrl+'\'
// When running ./ and then echo $? for the first time there 
// is an uninitialised valgrind error from ft_string_substitution-> 
// st_exit_code_subst-> ft_itoa-> ft_st_get_len
// tokenization should be run on arguments for regular commands
// quotes are wrongy included in the output of some things, such as echo
// school bash exports SHLVL to a vlaue always one smaller, ours doesnt
// Tokens and arguments can be given as <"abc"> but should be used as <abc>
// if we have Signals for stopping current line then maybe we can use status=0
// 	as default
// Cannot redirect specific outputs to files (2>stderr.txt) (2>/dev/null)