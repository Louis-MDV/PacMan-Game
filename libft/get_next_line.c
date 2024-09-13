/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 22:13:57 by louismdv          #+#    #+#             */
/*   Updated: 2024/03/12 21:34:34 by lmerveil         ###   ########.fr       */
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
	while ((ft_strchr(buff, '\n')) == 0 && read_ptr != 0)
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
		if (null_line(line) == 0)
			return (NULL);
		ft_strlcpy(line, stash, i + 1);
		if (ft_strchr(buff, '\n') != 0)
			ft_strcpy2(buff, ft_strchr(buff, '\n') + 1);
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

int	null_line(char *line)
{
	if (!line)
	{
		free(line);
		return (0);
	}
	return (1);
}
