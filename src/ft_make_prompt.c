/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_prompt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:23:13 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/03 17:48:51 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// writes the string <src> to <target> starting at the
// <pos> character and null terminating the result
static void	ft_write(char *src, char *target, int pos)
{
	int	i;

	i = -1;
	while (src[++i] != '\0')
		target[pos + i] = src[i];
	target[pos + i] = '\0';
}

// Allocates and returns a string consisting of
// the "Prompt" before each readline
// Uses getenv to get the pwd and prints it after
// whatever prompt is saved in PROMPT
// uses dynamic lengths, so very resilient
// return values needs to be freed
char	*ft_make_prompt(char ***envp)
{
	char	*prompt;
	char	*pwd;
	int		allocated_pwd;

	pwd = ft_get_env(*envp, "PWD");
	allocated_pwd = 0;
	if (pwd == NULL)
	{
		pwd = getcwd(NULL, 0);
		allocated_pwd = 1;
	}
	if (!pwd)
		return ("[NO PATH]");
	prompt = (char *)malloc((ft_strlen(pwd) + ft_strlen(PROMPT) + \
	ft_strlen(POST_PROMPT) + 1) * sizeof(char));
	if (!prompt)
	{
		if (allocated_pwd)
			free(pwd);
		return ("[NO PATH]");
	}
	ft_write(PROMPT, prompt, 0);
	ft_write(pwd, prompt, ft_strlen(PROMPT));
	ft_write(POST_PROMPT, prompt, ft_strlen(pwd) + ft_strlen(PROMPT));  
	if (allocated_pwd)
		free(pwd);
	return (prompt);
}