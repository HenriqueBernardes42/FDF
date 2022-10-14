/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbernard <hbernard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 04:56:02 by hbernard          #+#    #+#             */
/*   Updated: 2022/05/23 23:15:58 by hbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find(char const *s1, char const *set, int i, int start)
{
	int	set_position;

	set_position = 0;
	while (set[set_position])
	{
		if (s1[start] == set[set_position])
		{
			start = start + i;
			set_position = 0;
		}
		else
		{
			++set_position;
		}
	}
	return (start);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	long	first;
	long	last;
	int		i;
	size_t	s1_size;
	char	*s;

	i = 0;
	s1_size = ft_strlen(s1);
	first = find(s1, set, 1, 0);
	last = find(s1, set, -1, s1_size - 1);
	if ((last - first + 2) < 0)
		return (ft_strdup(""));
	s = ft_calloc((last - first + 2), sizeof(char));
	while ((first + i) < (last + 1))
	{
		s[i] = s1[first + i];
		++i;
	}
	s[i] = '\0';
	return (s);
}
