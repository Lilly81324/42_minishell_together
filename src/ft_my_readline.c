/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_my_readline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 18:06:58 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/27 18:07:32 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Essentially readline but differentiating between interactive mode and not
// Writes either prompt and input to terminal or if non interactive
// then writes them to /dev/null
// Frees *prompt
char	*ft_my_readline(char **prompt)
{
	int		ter_fd;
	int		std_fd;
	char	*input;

	std_fd = dup(STDOUT_FILENO);
	if (isatty(STDIN_FILENO) == 0)
		ter_fd = open("/dev/null", O_WRONLY);
	else
		ter_fd = open("/dev/tty", O_WRONLY);
	dup2(ter_fd, STDOUT_FILENO);
	close (ter_fd);
	input = readline(*prompt);
	dup2(std_fd, STDOUT_FILENO);
	close (std_fd);
	ft_null(prompt);
	return (input);
}
