/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdout_to_outfile.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:14:22 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/07 19:08:41 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Creates file to write to
// if it doesnt exist, make it
// if no permission to write to file return -1
// always truncate file to 0 bytes
// nominally return 0
static int	ft_check_file(char *name)
{
	int		acces;
	int		exist;

	exist = access(name, F_OK);
	if (exist != 0)
		return (0);
	acces = access(name, W_OK);
	if (acces == 0)
		return (0);
	printf(FILE_EXECUTE_NO_PERMISSION, name);
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
	outfile = open(filename, O_CREAT | O_TRUNC | O_WRONLY);
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
