/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdout_to_outfile.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:14:22 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/21 14:16:21 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// creates a file via touch wherever the name places it
static void	ft_touch_file(char *name)
{
	char	*path;
	char	*argv[3];
	pid_t	pid;

	path = ft_get_path("touch");
	argv[0] = "touch";
	argv[1] = name;
	argv[2] = NULL;
	pid = fork();
	if (pid < 0)
	{
		perror("Error creating fork\n");
		return ;
	}
	if (pid == 0)
		execve(path, argv, NULL);
	free(path);
	waitpid(pid, NULL, 0);
}

// creates a file via touch wherever the name places it
static void	ft_trunc_file(char *name, char *size)
{
	char	*path;
	char	*argv[5];
	pid_t	pid;

	path = ft_get_path("truncate");
	argv[0] = "truncate";
	argv[1] = "-s";
	argv[2] = size;
	argv[3] = name;
	argv[4] = NULL;
	pid = fork();
	if (pid < 0)
	{
		perror("Error creating fork\n");
		return ;
	}
	if (pid == 0)
		execve(path, argv, NULL);
	free(path);
	waitpid(pid, NULL, 0);
}

// Creates file to write to
// if it doesnt exist, make it
// if no permission to write to file return -1
// always truncate file to 0 bytes
// nominally return 0
static int	ft_check_file(char *name)
{
	int		exists;
	int		acces;

	exists = access(name, F_OK);
	if (exists != 0)
		ft_touch_file(name);
	acces = access(name, W_OK);
	if (acces == 0)
	{
		ft_trunc_file(name, "0");
		return (0);
	}
	perror("No Permission to open outfile");
	return (-1);
}

// opens a file by name in RDWR
// redirects STDOUT to that file
// closes the file itself directly
// returns -1 if error
int	ft_stdout_to_outfile(char *filename)
{
	int	outfile;

	if (ft_check_file(filename) != 0)
		return (-1);
	outfile = ft_cooler_open(filename);
	if (outfile < 0)
	{
		perror("Error opening outfile");
		return (-1);
	}
	if (dup2(outfile, STDOUT_FILENO) < 0)
	{
		perror("Error redirecting stdout to outfile");
		close(outfile);
		return (-1);
	}
	close(outfile);
	return (0);
}
