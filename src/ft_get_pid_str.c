/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_pid_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 17:16:01 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/19 17:46:05 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Creates the string from the buffer
static char	*st_cut_pid_buf(char *buf)
{
	int		i;
	char	*res;

	i = 0;
	while (buf[i] != '\0' && buf[i] != ' ')
		i++;
	res = (char *)malloc((i + 1) * sizeof(char));
	res[i] = '\0';
	while (--i >= 0)
		res[i] = buf[i];
	return (res);
}

// Gives back current pid as string
// Returns NULL if no access to /proc/self/stat
char	*ft_get_pid_str(void)
{
	int		fd;
	char	buf[100];
	char	*result;
	size_t	readd;

	fd = open("/proc/self/stat", O_RDONLY);
	if (fd < 0)
		return (NULL);
	readd = read(fd, buf, sizeof(buf) -1);
	buf[99] = '\0';
	close(fd);
	if (readd <= 0)
		return (NULL);
	result = st_cut_pid_buf(buf);
	return (result);
}
