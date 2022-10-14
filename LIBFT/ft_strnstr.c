/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbernard <hbernard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 06:11:18 by hbernard          #+#    #+#             */
/*   Updated: 2022/05/22 01:00:01 by hbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*loop(const char	*big, const char *little, size_t len)
{
	size_t		i;
	int			k;
	int			add;

	add = 0;
	i = 0;
	k = 0;
	while (i < len)
	{
		if (big[i] == little[k])
		{
			if (little[k + 1] == '\0')
				return ((char *)big + i - (ft_strlen(little) - 1));
			++k;
		}
		else
		{
			++add;
			k = 0;
		}
		i = k + add;
	}
	return (0);
}

char	*ft_strnstr(const char	*big, const char *little, size_t len)
{
	char	*str;

	if (ft_strlen(little) == 0)
		return ((char *)big);
	if (ft_strlen(big) == 0)
		return (NULL);
	str = loop(big, little, len);
	if (str != 0)
		return (str);
	return (0);
}
