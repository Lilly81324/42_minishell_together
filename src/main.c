/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybiloshy <ybiloshy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:56:42 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/25 15:56:43 by ybiloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int argc, char **argv, char **envp)
{
	char **new_env;

	(void)argv;
	(void)argc;
	new_env = ft_copy_env(envp);
	return (ft_loop(&new_env));
}

// TODO:
// Signaling
// Exit Codes
// Argument substitution
// Argument declaration?
// <<
// piping
// Ctrl+C makes newline
// builtins:
// echo with -n flag
// autocomplete of commands
// maybe remove handling of semicolon