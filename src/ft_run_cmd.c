/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:14:17 by sikunne           #+#    #+#             */
/*   Updated: 2025/04/08 19:23:55 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Runs command at <path> with arguments <argv> and envp <*shl->env>
// Gives back the exit code of programm into <status>
// Returns 0 if execution nominal, or 1 if Error
int	ft_run_cmd(char *path, char **argv, char ***env)
{
	pid_t	pid;
	int		temp;
	int		i;

	signal(SIGINT, ft_sig_quit);
	pid = fork();
	if (pid < 0)
	{
		ft_perror(FORK_ERROR, NULL, NULL);
		return (1);
	}
	if (pid == 0)
		execve(path, argv, *env);
	waitpid(pid, &temp, 0);
	signal(SIGINT, ft_sig_int);
	i = 0;
	while (argv[i] != NULL)
		i++;
	i--;
	if (i == 0)
		ft_update_last_arg(path, env);
	else
		ft_update_last_arg(argv[i], env);
	return (WEXITSTATUS(temp));
}
