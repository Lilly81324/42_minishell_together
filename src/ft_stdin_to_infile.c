/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdin_to_infile.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:13:26 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/24 17:23:14 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// opens a file by name in RD_ONLY
// redirects STDIN to that file
// closes the file itself directly
// returns -1 if errorr
int	ft_stdin_to_infile(char *filename)
{
	int	infile;

	infile = ft_cooler_open(filename);
	if (infile < 0)
	{
		perror("Error opening infile");
		return (-1);
	}
	if (dup2(infile, STDIN_FILENO) < 0)
	{
		perror("Error redirecting stdin to infile");
		close(infile);
		return (-1);
	}
	close(infile);
	return (0);
}
