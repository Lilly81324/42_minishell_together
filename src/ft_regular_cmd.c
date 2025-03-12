/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_regular_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:50:39 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/12 18:53:42 by sikunne          ###   ########.fr       */
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
int	ft_regular_cmd(t_shell *shl, int *pos)
{
	char	*path;
	char	**argv;
	int		status;

	path = ft_get_path(shl->tok[*pos], shl->env);
	if (path == NULL)
	{
		printf(INVALID_COMMAND, shl->tok[*pos]);
		shl->exit_code = ERNUM_CMD_NOTEXIST;
		return (0);
	}
	argv = ft_prepare_argv(shl->tok, pos);
	if (argv == NULL)
		return (2);
	status = ft_run_cmd(shl, path, argv);
	ft_cleanup(shl->tok, &argv, &path, pos);
	return (status);
}
