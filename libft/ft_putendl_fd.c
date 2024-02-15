/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:32:46 by louismdv          #+#    #+#             */
/*   Updated: 2023/11/22 16:05:04 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <unistd.h>

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s || !fd)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}

/* #include <unistd.h>
#include <fcntl.h>

int main() {
    // Open a file for writing (or use STDOUT_FILENO for standard output)
    int fileDescriptor = open("output2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fileDescriptor == -1) {
        perror("Error opening file");
        return 1;
    }

    // Test ft_putnbr_fd with various numbers
    ft_putendl_fd("train", fileDescriptor);
    ft_putendl_fd("12gog", fileDescriptor);
    ft_putendl_fd("  bonjour", fileDescriptor);

    // Close the file descriptor
    close(fileDescriptor);

    return 0;
}
 */