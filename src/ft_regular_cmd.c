/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_regular_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:50:39 by sikunne           #+#    #+#             */
/*   Updated: 2025/04/04 01:02:41 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// needed more lines >:c
static void	ft_cleanup(char **token, char ***argv, char **path, int *pos)
{
	int	len;

	len = 0;
	ft_nullc(argv);
	ft_null(path);
	while (ft_is_delimiter(token[len + (*pos)]) == 0)
		len++;
	(*pos) += len;
}

// Takes string for command with arguments and execves it
// ex: "echo -n lel" as input string
int	ft_regular_cmd(t_shell *shl, int *pos, char ***env)
{
	char	*path;
	char	**argv;
	int		status;

	path = ft_get_path(shl->tok[*pos], env);
	if (path == NULL)
	{
		ft_perror(INVALID_COMMAND, shl->tok[*pos], NULL);
		return (ERNUM_CMD_NOTEXIST);
	}
	status = ft_check_access(path, shl->tok[*pos]);
	if (status != 0)
	{
		ft_null(&path);
		return (status);
	}
	argv = ft_prepare_argv(shl->tok, pos);
	if (argv == NULL)
		return (2);
	status = ft_run_cmd(path, argv, env);
	ft_cleanup(shl->tok, &argv, &path, pos);
	return (status);
}
