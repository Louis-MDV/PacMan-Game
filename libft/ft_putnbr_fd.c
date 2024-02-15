/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:33:07 by louismdv          #+#    #+#             */
/*   Updated: 2023/11/23 10:32:18 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	char		digit;
	int long	nb2;

	digit = 0;
	nb2 = n;
	if (n < 0)
	{
		write(fd, "-", 1);
		nb2 = -nb2;
	}
	if (nb2 >= 0 && nb2 <= 9)
	{
		digit = (nb2 + '0');
		write(fd, &digit, 1);
	}
	else
	{
		ft_putnbr_fd((nb2 / 10), fd);
		ft_putnbr_fd((nb2 % 10), fd);
	}
}

/* #include <unistd.h>
#include <fcntl.h>

void ft_putnbr_fd(int n, int fd);

int main() {
    // Open a file for writing (or use STDOUT_FILENO for standard output)
    int fileDescriptor = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fileDescriptor == -1) {
        perror("Error opening file");
        return 1;
    }

    // Test ft_putnbr_fd with various numbers
    ft_putnbr_fd(123, fileDescriptor);
    ft_putnbr_fd(-456, fileDescriptor);
    ft_putnbr_fd(7890, fileDescriptor);

    // Close the file descriptor
    close(fileDescriptor);

    return 0;
}
 */