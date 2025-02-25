/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:54:23 by sikunne           #+#    #+#             */
/*   Updated: 2024/11/28 15:40:48 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// for read, null and size_t
# include <unistd.h>
// for malloc
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
int		ft_pos_char_str(char *string, char c);
void	ft_str_n_cpy(char **dest, char *src);
ssize_t	ft_append_line(int fd, char **buffer);
void	ft_remove_line(char **buffer);
void	*free_buffer(char **buffer);

#endif
