/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:56:42 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/28 18:31:44 by sikunne          ###   ########.fr       */
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