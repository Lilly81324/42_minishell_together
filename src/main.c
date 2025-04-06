/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:56:42 by sikunne           #+#    #+#             */
/*   Updated: 2025/04/06 17:27:06 by sikunne          ###   ########.fr       */
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
// change the thing in ft_builtin_cmd
// (heredocs dont need to be LL make them an array)
// _ does not owrk properly
// 1: can take redirs as last arg
// 2: should save full binary path for commands
// 3: show only binary name with echo $_
// make builtins stop at last argument?
// following quotes without psaces are one token "1""2""3" -> 123
// Broken pipes not detected, but occur: "yes | echo hi"
// echo ' 		added  		by me		' does not print the last space unlike bash
// Signals:
// Ctrl+D does not close in HEREDOCS? check on work Pc

// Fixes fo testers:
// ?Display prompt in non interactive mode?