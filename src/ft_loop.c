/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:46:42 by sikunne           #+#    #+#             */
/*   Updated: 2025/04/03 18:38:45 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	st_get_input(t_shell *shl, char ***envp, char **input)
{
	char	*prompt;

	prompt = ft_make_prompt(envp);
	*input = ft_my_readline(prompt);
	ft_null(&prompt);
	if (g_sig == SIGINT)
	{
		g_sig = 0;
		shl->exit_code = ERNUM_CTRLC;
		ft_null(input);
		return (1);
	}
	return (0);
}

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
	char	*input;
	int		status;
	t_shell	shl;

	shl.env = envp;
	shl.exit_code = 0;
	rl_catch_signals = 0;
	while (1)
	{
		shl.tok = NULL;
		shl.heredoc_pos = 0;
		shl.start = NULL;
		input = NULL;
		if (st_get_input(&shl, envp, &input) == 1)
			continue ;
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
