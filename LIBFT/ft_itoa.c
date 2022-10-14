/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbernard <hbernard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:28:38 by hbernard          #+#    #+#             */
/*   Updated: 2022/05/22 05:52:54 by hbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	power_of(long pow, long n, int *n_len)
{
	long	cp_n;

	cp_n = n;
	*n_len = 0;
	pow = 1;
	if (n < 0)
		n = n * -1;
	while (n > 9)
	{
		pow = pow * 10;
		n = n / 10;
		*n_len += 1;
	}
	if ((cp_n / pow) < 0)
		*n_len = *n_len + 2;
	else
		++*n_len;
	return (pow);
}

char	*ft_itoa(int n)
{
	char	*string;
	long	pow;
	int		*len;
	int		i;
	long	m;

	len = &i;
	m = n;
	pow = power_of(0, m, len);
	string = ft_calloc((i + 1), sizeof(char));
	i = 0;
	while (pow)
	{
		string[i] = ((m / pow) % 10) + 48;
		if (i == 0 && (m * -1) > 0)
		{
			m = m * -1;
			pow *= 10;
			string[i] = '-';
		}
		pow /= 10;
		++i;
	}
	string[i] = '\0';
	return (string);
}
