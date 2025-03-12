/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:14:17 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/12 18:05:00 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Runs command at <path> with arguments <argv> and envp <envp>
// Gives back the exit code of programm into <status>
// Returns 0 if execution nominal, or 1 if Error
int	ft_run_cmd(t_shell *shl, char *path, char **argv)
{
	pid_t	pid;
	int		temp;

	pid = fork();
	if (pid < 0)
	{
		printf(FORK_ERROR);
		return (1);
	}
	if (pid == 0)
		execve(path, argv, *shl->env);
	waitpid(pid, &temp, 0);
	shl->exit_code = WEXITSTATUS(temp);
	return (0);
}
