/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbernard <hbernard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 23:21:24 by hbernard          #+#    #+#             */
/*   Updated: 2022/10/14 06:51:56 by hbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include	<stdlib.h>
# include	<unistd.h>

char	*get_next_line(int fd);
char	*ft_strjoin_gnl(char *str, char *buffer);
size_t	len_gnl(char *s);
#endif
