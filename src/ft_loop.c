/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:46:42 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/12 19:26:56 by sikunne          ###   ########.fr       */
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
	while (1)
	{
		shl.tok = NULL;
		prompt = ft_make_prompt(envp);
		input = readline(prompt);
		ft_null(&prompt);
		add_history(input);
		if (input == NULL) //Ctrl+D -> should exit
			return (0);
		status = ft_handle_input(&input, &shl);
		ft_null(&input);
		if (status >= 2)
		{
			printf("Ending with exit code: %i\n", shl.exit_code);
			clear_history();
			ft_nullb(envp);
			return (shl.exit_code);
		}
	}
	return (0);
}

// CTRL+C -> new line
// CTRL+D -> exit