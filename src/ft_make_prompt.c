/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_prompt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:23:13 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/05 18:42:20 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// writes the string <src> to <target> starting at the
// <pos> character and null terminating the result
static void	st_write(char *src, char *target, int pos)
{
	int	i;

	i = -1;
	while (src[++i] != '\0')
		target[pos + i] = src[i];
	target[pos + i] = '\0';
}

// Allocates and Fills the prompt with the required content
static char	*st_promp_assign(int allocated_pwd, char *pwd)
{
	char	*prompt;

	prompt = (char *)malloc((ft_strlen(pwd) + ft_strlen(PROMPT) + \
	ft_strlen(POST_PROMPT) + 1) * sizeof(char));
	if (!prompt)
	{
		if (allocated_pwd)
			free(pwd);
		return (NULL);
	}
	st_write(PROMPT, prompt, 0);
	st_write(pwd, prompt, ft_strlen(PROMPT));
	st_write(POST_PROMPT, prompt, ft_strlen(pwd) + ft_strlen(PROMPT));
	return (prompt);
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
		return (NULL);
	prompt = st_promp_assign(allocated_pwd, pwd);
	if (prompt == NULL)
		return (NULL);
	if (allocated_pwd)
		free(pwd);
	return (prompt);
}
