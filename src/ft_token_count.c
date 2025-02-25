/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_count.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:35:33 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/17 17:38:25 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// moves until it reaches end or opt
// returns the index of that character
// returns -1 if character not found (quotation opened and not closed)
static int	move_until(char *s, int i, char opt)
{
	i++;
	while (s[i] != opt && s[i] != '\0')
		i++;
	if (s[i] == '\0')
		return (-1);
	return (i);
}

// returns index of character that is not regular
// so either a SPACES or a SPECIALS or a \0
static int	move_regulars(char *s, int *i)
{
	while (s[*i] != '\0' && ft_c_in_s(SPACES, s[*i]) == 0 && \
			ft_c_in_s(SPECIALS, s[*i]) == 0)
	{
		if (s[*i] == '\'')
			*i = move_until(s, *i, '\'');
		else if (s[*i] == '\"')
			*i = move_until(s, *i, '\"');
		if (*i < 0)
			return (-1);
		(*i)++;
	}
	return (*i);
}

// if >abc moves to next, if >>abc moves to next next
// if abc doesnt move
static int	move_specials(char *s, int *i)
{
	if (ft_c_in_s(SPECIALS, s[*i]) == 0)
		return (*i);
	if (s[*i] == '>' && s[(*i) + 1] == '>')
		(*i) += 2;
	else if (s[*i] == '<' && s[(*i) + 1] == '<')
		(*i) += 2;
	else
		(*i)++;
	return (*i);
}

// returns how many tokens are in a string
// returns -1 if error
int	ft_token_count(char *s)
{
	int		i;
	int		strings;

	i = 0;
	strings = 0;
	while (s[i] != '\0')
	{
		ft_skip_spaces(&i, s);
		if (s[i] != '\0')
			strings++;
		if (i != move_specials(s, &i))
			continue ;
		move_regulars(s, &i);
		if (i < 0)
			return (-1);
	}
	return (strings);
}
