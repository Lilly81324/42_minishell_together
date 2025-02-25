/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:32:28 by sikunne           #+#    #+#             */
/*   Updated: 2024/11/28 15:40:37 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <fcntl.h>
// #include <stdio.h>
#include "./get_next_line.h"

// gets the next line from a file desciptor, delimited by \n or EOF
char	*get_next_line(int fd)
{
	static char	*buffer;
	ssize_t		bytes_read;
	char		*ret_string;
	size_t		buff_size;

	if (fd < 0)
		return (NULL);
	if (!buffer)
	{
		buffer = (char *)malloc(1);
		buffer[0] = '\0';
	}
	bytes_read = 1;
	while (ft_pos_char_str(buffer, '\n') == -1 && bytes_read > 0)
		bytes_read = ft_append_line(fd, &buffer);
	if (buffer[0] == '\0' || bytes_read == -1)
		return (free_buffer(&buffer));
	if (ft_pos_char_str(buffer, '\n') == -1)
		buff_size = ft_pos_char_str(buffer, '\0');
	else
		buff_size = ft_pos_char_str(buffer, '\n') + 1;
	ret_string = (char *)malloc((buff_size + 1) * sizeof(char));
	ft_str_n_cpy(&ret_string, buffer);
	ft_remove_line(&buffer);
	return (ret_string);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*str;

// 	fd = open("empty.txt", O_RDONLY);
// 	str = get_next_line(fd);
// 	while (str != NULL)
// 	{
// 		printf("%s", str);
// 		if (str != NULL)
// 			free(str);
// 		str = get_next_line(fd);
// 	}
// 	printf("NULL REACHED\n");
// 	return (0);
// }
