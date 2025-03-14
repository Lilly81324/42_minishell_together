/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:14:17 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/14 17:08:39 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Runs command at <path> with arguments <argv> and envp <*shl->env>
// Gives back the exit code of programm into <status>
// Returns 0 if execution nominal, or 1 if Error
int	ft_run_cmd(t_shell *shl, char *path, char **argv)
{
	pid_t	pid;
	int		temp;
	int		i;

	pid = fork();
	if (pid < 0)
	{
		ft_perror(FORK_ERROR, NULL, NULL);
		return (1);
	}
	if (pid == 0)
		execve(path, argv, *shl->env);
	waitpid(pid, &temp, 0);
	i = 0;
	while (argv[i] != NULL)
		i++;
	i--;
	ft_update_last_arg(shl, argv[i]);
	shl->exit_code = WEXITSTATUS(temp);
	return (0);
}
