/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbernard <hbernard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 04:15:39 by hbernard          #+#    #+#             */
/*   Updated: 2022/05/25 23:23:37 by hbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*ptr;
	size_t		i;
	size_t		s_len;

	i = 0;
	s_len = ft_strlen(s);
	if (start > s_len)
		return (ft_strdup(""));
	if ((s_len - start) < s_len)
		s_len = s_len - start;
	if (len < s_len)
		s_len = len;
	ptr = ft_calloc((s_len + 1), sizeof(char));
	if (ptr != NULL)
	{
		while (i < len && s[start])
		{
			ptr[i] = s[start];
			++start;
			++i;
		}
		return (ptr);
	}
	return (NULL);
}
