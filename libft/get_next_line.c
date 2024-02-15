/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 22:13:57 by louismdv          #+#    #+#             */
/*   Updated: 2024/02/14 17:23:43 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	ssize_t		read_ptr;
	static char	buff[BUFFER_SIZE + 1];
	char		*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_ptr = 1;
	if (ft_strlen2(buff) > 0)
	{
		stash = ft_strdup2(buff);
	}
	else
		stash = NULL;
	while ((ft_strchr2(buff, '\n')) == 0 && read_ptr != 0)
	{
		read_ptr = read(fd, buff, BUFFER_SIZE);
		if (read_ptr == -1)
			return (0);
		buff[read_ptr] = '\0';
		if (stash == NULL)
			stash = ft_strdup2(buff);
		else
			stash = ft_strjoin2(stash, buff);
	}
	return (extract_line(stash, read_ptr, buff));
}

char	*extract_line(char *stash, ssize_t read_ptr, char *buff)
{
	char	*line;
	int		i;

	i = 0;
	if (stash != NULL && read_ptr != 0)
	{
		while (stash[i] && stash[i] != '\n')
			i++;
		if (stash[i] == '\n')
			i++;
		line = (char *)malloc(sizeof(char) * (i + 1));
		if (!line)
		{
			free(line);
			return (NULL);
		}
		ft_strlcpy2(line, stash, i + 1);
		if (ft_strchr2(buff, '\n') != 0)
			ft_strcpy2(buff, ft_strchr2(buff, '\n') + 1);
		free(stash);
		return (line);
	}
	else if (read_ptr == 0 && ft_strlen2(stash) < 1)
	{
		free(stash);
		return (0);
	}
	return (stash);
}

char	*ft_strchr2(const char *s, int c)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	return (0);
}

// #include <fcntl.h>
// #include <stdio.h>

// int	main(void)
// {
// 	int		fd;
// 	char	*str;

// 	fd = open("text.txt", O_RDONLY);
// 	while ((str = get_next_line(fd)))
// 	{
// 		printf("%s", str);
// 		free(str);
// 	}
// 	str = get_next_line(fd);
// 	printf("%s\n", str);
// 	close(fd);
// 	free(str);
// }
