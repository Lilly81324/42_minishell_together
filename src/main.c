/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:56:42 by sikunne           #+#    #+#             */
/*   Updated: 2025/04/07 18:30:51 by sikunne          ###   ########.fr       */
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
// change the thing in ft_builtin_cmd
// (heredocs dont need to be LL make them an array)
// following quotes without spaces are one token "1""2""3" -> 123
// echo ' 		added  		by me		' does not print the last space unlike bash
// Signals:
// Ctrl+D does not close in HEREDOCS? check on work Pc
// After ^ and using CtrlC, input is not treated correctly, no CtrlD and no input used

// Fixes fo testers:
// ?Display prompt in non interactive mode?