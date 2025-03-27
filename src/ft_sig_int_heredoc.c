/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sig_int_heredoc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:13:27 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/27 17:43:40 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Ctrl+C Signal
// Displays a new line
// Clears current input, Mark new readline, displays last prompt again
void	ft_sig_int_heredoc(int sig)
{
	(void)sig;
	ft_write_string("\nyay its working\n");
	write(STDOUT_FILENO, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}
