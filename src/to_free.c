/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbernard <hbernard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 00:27:14 by hbernard          #+#    #+#             */
/*   Updated: 2022/10/14 03:12:08 by hbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func_header.h"

void	free_split(char **splt)
{
	int	i;

	i = 0;
	while (splt[i])
		free(splt[i++]);
	free(splt);
}

void	free_gnl(char *line, char **splited )
{
	free_split(splited);
	free(line);
}

char	*special_case(char *line, char **splitted, int fd)
{
	free_gnl(line, splitted);
	line = get_next_line(fd);
	return (line);
}
