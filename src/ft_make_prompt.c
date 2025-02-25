/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_prompt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:23:13 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/24 15:57:38 by sikunne          ###   ########.fr       */
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
	int		len_pwd;
	int		len_pro;
	int		len_post;
	char	*pwd;

	pwd = ft_get_env(*envp, "PWD");
	if (pwd == NULL)
		pwd = "NO_PATH";
	len_pwd = ft_strlen(pwd);
	len_pro = ft_strlen(PROMPT);
	len_post = ft_strlen(POST_PROMPT);
	prompt = (char *)malloc((len_pwd + len_pro + len_post + 1) * sizeof(char));
	ft_write(PROMPT, prompt, 0);
	ft_write(pwd, prompt, len_pro);
	ft_write(POST_PROMPT, prompt, len_pwd + len_pro);
	return (prompt);
}
