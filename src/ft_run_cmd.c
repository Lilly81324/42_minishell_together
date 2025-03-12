/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:14:17 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/12 17:43:43 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Runs command at <path> with arguments <argv> and envp <envp>
// Gives back the exit code of programm into <status>
// Returns 0 if execution nominal, or 1 if Error
int	ft_run_cmd(char *path, char **argv, char **envp, int *status)
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
		execve(path, argv, envp);
	waitpid(pid, &temp, 0);
	*status = WEXITSTATUS(temp);
	return (0);
}
