/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbernard <hbernard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:08:14 by hbernard          #+#    #+#             */
/*   Updated: 2022/05/09 16:15:29 by hbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	char_c;

	char_c = (char) c;
	i = 0;
	if (ft_isascii(c) == 0)
		return ((char *)s);
	while (s[i])
	{
		if (s[i] == char_c)
			return (((char *)(s + i)));
		++i;
	}
	if (c == '\0')
		return ((char *)(s + i));
	if (s[i] == '\0')
		return (0);
	return ((char *) s);
}
