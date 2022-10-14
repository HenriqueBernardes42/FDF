/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbernard <hbernard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:20:38 by hbernard          #+#    #+#             */
/*   Updated: 2022/10/14 02:35:51 by hbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"func_header.h"
#include	"math.h"

int	col_len(char **line_separated)
{
	int	i;

	i = 0;
	while (line_separated[i])
		++i;
	return (i);
}

t_next	s_target(int current, int prev, t_next next, int size)
{
	t_next	target;

	target.x = next.x + size + 1;
	target.y = next.y + size + current - prev - (size / 2);
	return (target);
}

int	def_size(int n_lines)
{
	int	size;

	size = (WIN_HEI / n_lines) / 2;
	if ((size - 5) > 0)
		size -= 5;
	return (size);
}

int	s_color(char **line_separated, int i)
{
	char	**split;
	char	*color;

	split = ft_split(line_separated[i], ',');
	if (split[1] != NULL )
	{
		color = ft_strdup(split[1]);
		free(split[0]);
		free(split[1]);
		free(split);
		return (hex_to_int(color));
	}
	free_split(split);
	return (PINK);
}

int	hex_to_int(char *hexadecimal)
{
	int		i;
	int		decimal;
	int		length;
	char	digit;

	i = 0;
	decimal = 0;
	length = ft_strlen(hexadecimal);
	i = 0;
	while (i < length)
	{
		digit = ft_toupper(hexadecimal[length - i - 1]);
		if (digit >= '0' && digit <= '9')
			decimal += (digit - '0') * pow(16, i);
		else
			decimal += (digit - 'A' + 10) * pow(16, i);
		++i;
	}
	free(hexadecimal);
	return (decimal);
}
