/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbernard <hbernard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 03:04:25 by hbernard          #+#    #+#             */
/*   Updated: 2022/05/09 16:16:22 by hbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	size_s;
	char	char_c;

	char_c = (char) c;
	size_s = ft_strlen(s);
	while ((s + size_s) >= s)
	{
		if (s[size_s] == char_c)
			return ((char *)(s + size_s));
		--size_s;
	}
	return (NULL);
}
