/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:46:42 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/03 18:19:06 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Central loop called when input is given
int	ft_loop(char ***envp)
{
	char	*prompt;
	char	*input;
	int		status;

	while (1)
	{
		prompt = ft_make_prompt(envp);
		input = readline(prompt);
		ft_null(&prompt);
		add_history(input);
		if (input == NULL) //Ctrl+D -> should exit
			return (0);
		status = ft_handle_input(input, envp);
		ft_null(&input);
		if (status >= 1000)
		{
			clear_history();
			ft_nullb(envp);
			return (status - 1000);
		}
	}
	return (0);
}

// CTRL+C -> new line
// CTRL+D -> exit