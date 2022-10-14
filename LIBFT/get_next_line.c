/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbernard <hbernard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 22:39:22 by hbernard          #+#    #+#             */
/*   Updated: 2022/10/14 06:54:34 by hbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	there_it_is(char *s, int c)
{
	int		position;

	position = 0;
	if (!s)
		return (0);
	while (s[position])
	{
		if (s[position] == c)
			return (1);
		++position;
	}
	return (0);
}

char	*bild_line(char *str)
{
	int		i;
	char	*new_str;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		++i;
	++i;
	new_str = malloc((i + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		new_str[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

char	*new_reminder(char *str)
{
	int		i;
	int		j;
	char	*reminder;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	reminder = malloc((len_gnl(str) - i + 1) * sizeof(char));
	if (!reminder)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		reminder[j++] = str[i++];
	reminder[j] = '\0';
	free(str);
	return (reminder);
}

char	*ft_read(int fd, char *str)
{
	char	*buffer;
	int		i;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	i = 1;
	while (!there_it_is(str, '\n') && i != 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[i] = '\0';
		str = ft_strjoin_gnl(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = ft_read(fd, str);
	if (!str)
		return (NULL);
	line = bild_line(str);
	str = new_reminder(str);
	return (line);
}
