/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbernard <hbernard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 04:53:22 by hbernard          #+#    #+#             */
/*   Updated: 2022/10/14 06:56:37 by hbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**alloc(int count_words, char c, char const *s, char **split)
{
	int			i;
	int			start;
	size_t		end;
	size_t		s_len;

	start = 0;
	i = 0;
	s_len = ft_strlen(s);
	while (i < count_words)
	{
		if (s[0] != c && i == 0)
			start = 0;
		else
		{
			while (s[start] == c)
				++start;
		}
		end = start;
		while (end < s_len && s[end] != c)
			++end;
		split[i] = ft_substr(s, start, end - start);
		++i;
		start = end;
	}
	return (split);
}

char	**ft_split(char const *s, char c)
{
	int			count_words;
	char		**split;
	int			i;

	i = 0;
	count_words = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			++count_words;
		++i;
	}
	split = ft_calloc((count_words + 1), sizeof(char *));
	alloc(count_words, c, s, split);
	return (split);
}
