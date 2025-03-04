/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_regular_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:50:39 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/04 16:09:12 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// returns 1 if absolute command like /usr/bin/echo
// or ./a.out
// or 0 if not
static int	ft_check_abs_cmds(char **arg)
{
	if (arg[0] == NULL || ft_strlen(arg[0]) < 3)
		return (0);
	if (arg[0][0] == '/')
		return (1);
	if (arg[0][0] == '.' && arg[0][1] == '/')
		return (1);
	return (0);
}

// needed more lines >:c
static void	ft_cleanup(char **arg, char ***argv, char **path, int *pos)
{
	int	len;

	len = 0;
	ft_nullc(argv);
	ft_null(path);
	while (ft_is_delimiter(arg[len + (*pos)]) == 0)
		len++;
	(*pos) += len;
}

// Takes string for command with arguments and execves it
// ex: "echo -n lel" as input string
int	ft_regular_cmd(char **arg, int *pos, char ***envp)
{
	char	*path;
	pid_t	pid;
	char	**argv;

	if (ft_check_abs_cmds(arg) == 1)
		return (ft_abs_commands(arg, pos));
	path = ft_get_path(arg[*pos]);
	if (path == NULL)
	{
		printf(INVALID_COMMAND);
		return (1);
	}
	argv = ft_prepare_argv(arg, pos);
	pid = fork();
	if (pid < 0)
	{
		printf(FORK_ERROR);
		return (1);
	}
	if (pid == 0)
		execve(path, argv, *envp);
	waitpid(pid, NULL, 0);
	ft_cleanup(arg, &argv, &path, pos);
	return (-1);
}
