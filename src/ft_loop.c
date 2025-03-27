/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:46:42 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/27 18:09:01 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	st_cleanup(char ***envp)
{
	clear_history();
	ft_nullb(envp);
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
}

// Central loop called when input is given
int	ft_loop(char ***envp)
{
	char	*prompt;
	char	*input;
	int		status;
	t_shell	shl;

	shl.env = envp;
	shl.exit_code = 0;
	while (1)
	{
		shl.tok = NULL;
		shl.heredoc_pos = 0;
		shl.start = NULL;
		prompt = ft_make_prompt(envp);
		input = st_my_readline(&prompt);
		add_history(input);
		status = ft_handle_input(&input, &shl);
		ft_null(&input);
		if (status >= 2)
		{
			st_cleanup(envp);
			return (shl.exit_code);
		}
	}
	return (0);
}
