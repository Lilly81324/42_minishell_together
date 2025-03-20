/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:46:42 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/20 17:52:46 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Central loop called when input is given
int	ft_loop(char ***envp)
{
	char	*prompt;
	char	*input;
	int		status;
	t_shell	shl;

	shl.env = envp;
	shl.exit_code = 0;
	shl.start = NULL;
	while (1)
	{
		shl.tok = NULL;
		shl.heredoc_pos = 0;
		prompt = ft_make_prompt(envp);
		input = readline(prompt);
		ft_null(&prompt);
		add_history(input);
		status = ft_handle_input(&input, &shl);
		ft_null(&input);
		if (status >= 2)
		{
			clear_history();
			ft_nullb(envp);
			return (shl.exit_code);
		}
	}
	return (0);
}

// CTRL+C -> new line
// CTRL+D -> exit