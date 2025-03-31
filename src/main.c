/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:56:42 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/31 18:26:36 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

volatile sig_atomic_t	g_sig = 0;

int	main(int argc, char **argv, char **envp)
{
	char	**new_env;

	(void)argv;
	(void)argc;
	if (argc > 1)
	{
		ft_perror(ARGC_START, NULL, NULL);
		return (ERNUM_START_ARGC);
	}
	signal(SIGINT, ft_sig_int);
	signal(SIGQUIT, ft_sig_quit);
	new_env = ft_copy_env(envp);
	ft_initial_shlvl(&new_env);
	return (ft_loop(&new_env));
}

// TODO:
// valgrind error on first Ctrl+C use
// maybe remove handling of semicolon
// Remove custom shortcuts from non-interactive mode?
// Pipes need to be ran in a subshell
// Pipes need to run concurrently, this is what bash does, and it helps with 
// piping big files that are too big for the pipe character buffer
// Dont treat redirection as delimiters for commands "echo abc >out.txt def ghi"
// should be echoing all of that, and regular commads should get all arguments
// as well, "./prog arg1 >out.txt arg2" gets both args
// In the spirit of concurrent pipes, running
// "error command | regular command" shold set exit code to 0, not 1

// Fixes fo testers:
// ?Display prompt in non interactive mode?
// Do not expand $ if spacer is next char (or EOS or ' or ")
// exporting "something" without = sets exit code to 0, not 1
// an exported variables name must start with a non number, otherwise error
// does not perror exit when running builtin exit in non interactive mode
// Made file redirection errors set exit code to 1
// Invalid abs commands say "No such file or directory"
// Invalid regular commands say "Command not found"