/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:11:33 by sikunne           #+#    #+#             */
/*   Updated: 2024/11/14 16:37:47 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// write the string s to file with file desc. fd..
// ..and add a pretty '\n' for formatting
void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s == NULL)
		return ;
	while (s[i] != '\0')
	{
		write(fd, &s[i], sizeof(char));
		i++;
	}
	write(fd, "\n", sizeof(char));
}
