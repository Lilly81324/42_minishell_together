/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:53:20 by sikunne           #+#    #+#             */
/*   Updated: 2024/11/14 16:36:41 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// writes the letter c into the file with file descr. fd
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, sizeof(char));
}
