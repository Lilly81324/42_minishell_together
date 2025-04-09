/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_extractor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:37:24 by sikunne           #+#    #+#             */
/*   Updated: 2025/04/09 14:00:26 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// moves until it reaches end or opt
// returns the index of that character
// returns -1 if character not found (quotation opened and not closed)
static int	move_until(char *s, int i, char opt)
{
	if (s[i] != '\0')
		i++;
	while (s[i] != opt && s[i] != '\0')
		i++;
	if (s[i] == '\0')
		return (-1);
	return (i);
}

// returns index of character that is not regular
// so either a SPACES or a SPECIALS or a \0
static void	move_regulars(char *s, int *i)
{
	while (s[*i] != '\0' && ft_find_c(s[*i], SPACES) == -1 && \
ft_find_c(s[*i], SPECIALS) == -1)
	{
		if (s[*i] == '\'')
			*i = move_until(s, *i, '\'');
		else if (s[*i] == '\"')
			*i = move_until(s, *i, '\"');
		if (*i < 0)
			return ;
		(*i)++;
	}
	return ;
}

// if >abc moves to next, if >>abc moves to next next
// if abc doesnt move
static void	move_specials(char *s, int *i)
{
	if (ft_find_c(s[*i], SPECIALS) == -1)
		return ;
	if (s[*i] == '>' && s[(*i) + 1] == '>')
		(*i) += 2;
	else if (s[*i] == '<' && s[(*i) + 1] == '<')
		(*i) += 2;
	else
		(*i)++;
	return ;
}

// called with the index of where a token begins
// moves i to the index of the end of that string (the character after)
// allocates and returns a string from the initial i to the end
static char	*get_token(char *s, int *i)
{
	int		start;
	char	*str;
	int		j;

	start = *i;
	if (ft_find_c(s[*i], SPECIALS) != -1)
		move_specials(s, i);
	else
		move_regulars(s, i);
	str = (char *)malloc((((*i) - start) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	j = -1;
	while (++j < ((*i) - start))
		str[j] = s[start + j];
	str[j] = '\0';
	return (str);
}

// sets the <result> to all the tokens extracted from <s>
// <result> should already be allocated for its length
// result will be NULL in case of error and will already be freed and cleaned
void	ft_token_extractor(char *s, char ***result)
{
	int	arrpos;
	int	i;

	arrpos = 0;
	i = 0;
	while (s[i] != '\0')
	{
		ft_skip_spaces(&i, s);
		if (s[i] != '\0')
		{
			(*result)[arrpos] = get_token(s, &i);
			if ((*result)[arrpos] == NULL)
			{
				ft_nullb(result);
				return ;
			}
			arrpos++;
		}
	}
	(*result)[arrpos] = NULL;
}
