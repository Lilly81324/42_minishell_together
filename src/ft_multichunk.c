/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multichunk.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:07:08 by sikunne           #+#    #+#             */
/*   Updated: 2025/04/02 18:30:48 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Execute this for every chunk
static int	st_placeholder(t_shell *shl, int *pos, t_sushl *head)
{
	int		i;
	t_sushl	*node;
	int		status;

	i = -1;
	node = head;
	while (++i < shl->subshl_pos)
		node = node->next;
	printf("Moved to node %i in placeholder\n", node->num);
	status = ft_subchunk(shl->tok, i, node->env);
	printf("Returning status %i\n", status);
	while (ft_is_delimiter(shl->tok[*pos]) != 1)
		(*pos)++;
	return (status);
}

int	ft_multichunk(t_shell *shl, int *std)
{
	int			i;
	int			status;
	int			last_pipe;
	t_sushl		*head;

	// For all piped chunks
	i = 0;
	status = 0;
	last_pipe = -1;
	head = ft_sushls_setup(shl);
	while (shl->tok[i] != NULL)
	{
		// For each piped chunk:
		ft_std_reset(std);
		status = st_pipes(shl, i, &last_pipe);
		if (status != 0)
			break ;
		// have each process terminate with their exit code
		// dont care about status
		status = st_placeholder(shl, &i, head);
		// wait until all commands are done
		// set exit code to last ones exit code
		if (status != 0)
			break ;
		if (shl->tok[i] != NULL)
			i++;
	}
	ft_b_close(&last_pipe);
	ft_sushl_clear(head);
	return (status);
}
